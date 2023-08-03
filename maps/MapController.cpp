#include "MapController.h"

#include <utility>

std::pair<int, int> MapController::convertGlobalToMapCoord(int x, int y) {
    int cellX = floor((x / sqrt(3) - y / 3.0) + 0.5);
    int cellY = floor(2.0 * y / 3.0 + 0.5);
    return std::make_pair(cellX + cellY / 2, cellY);
}

void MapController::setMap(std::shared_ptr<Map> map) {
    this->map = std::move(map);
}

void MapController::onCellClicked(int x, int y) {
    if (!isInBounds({x, y})) return;
    auto cell = map->getCell(x, y);
    if (cell->hasUnit()) {
        auto unit = cell->getUnit();

        if (unit->getPlayer()->getNumber() == turn) {
            selectUnit(std::move(unit));
            selectedUnitArea = generateMovementArea({x, y}, selectedUnit->getMovePoints());
        } else if (selectedUnit) {
            bool died = attackUnit(selectedUnit, unit);

            if (died) {
                moveUnit(selectedUnit, x, y);
                selectedUnitArea = generateMovementArea({x, y}, selectedUnit->getMovePoints());
            }
        }
    } else if (selectedUnit && selectedUnitArea.isIn(x, y)) {
        moveUnit(selectedUnit, x, y);
        selectedUnitArea = generateMovementArea({x, y}, selectedUnit->getMovePoints());
    }
}

void MapController::selectUnit(std::shared_ptr<Unit> unit) {
    deselectUnit();
    selectedUnit = std::move(unit);
}

void MapController::deselectUnit() {
    selectedUnit = nullptr;
    selectedUnitArea.clear();
}

void MapController::render(std::shared_ptr<Batch> batch) {
    const double hexagonSize = 100;
    auto& field = map->getField();
    std::shared_ptr<Batch> cellBatch = std::make_shared<Batch>(*batch);
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            cellBatch->update(batch, j * (Cell::SIZE * sqrt(3) / 2.0) +
                                     (i % 2) * Cell::SIZE * sqrt(3) / 4.0,
                              i * Cell::SIZE * 3 / 4);

            if (selectedUnitArea.isIn(j, i))
                field.at(i).at(j)->render(cellBatch, Cell::SELECTED);
            else
                field.at(i).at(j)->render(cellBatch, Cell::NO_EFFECT);
        }
    }

}

std::shared_ptr<const Map> MapController::getMap() const {
    return map;
}

void MapController::addUnit(int x, int y, std::shared_ptr<Unit> unit) {
    map->getField().at(y).at(x)->setUnit(std::move(unit));
}

void MapController::moveUnit(std::shared_ptr<Unit> unit, int x, int y) {
    unit->getCell()->eraseUnit();
    map->getCell(x, y)->setUnit(std::move(unit));
}

MovementArea MapController::generateMovementArea(Point p, unsigned int movePoints) const {
    MovementArea area;

    std::set<std::pair<int, Point> > queue;
    std::unordered_map<Point, decltype(queue)::iterator> iterators;
    iterators[p] = queue.insert({0, p}).first;
    while (!queue.empty()) {
        auto[dist, v] = *queue.begin();
        queue.erase(queue.begin());
        if (dist > movePoints) continue;
        if (!isInBounds(v)) continue;
        if (area.isIn(v)) continue;
        area.addCell(v);
        auto neighbours = getNeighbours(v);
        for (auto& i: neighbours) {
            auto cost = movementCost(v, i);
            if (cost == std::numeric_limits<unsigned int>::max()) continue;
            if (iterators.find(i) == iterators.end()) {
                iterators[i] = queue.insert({dist + cost, i}).first;
                continue;
            }
            if (iterators[i]->first < dist + cost) continue;
            queue.insert({dist + cost, i}).first;
        }
    }
    return area;
}

std::vector<Point> MapController::getNeighbours(Point p) {
    std::vector<std::vector<Point> > directions = {
            {{+1, 0}, {0,  -1}, {-1, -1},
                    {-1, 0}, {-1, +1}, {0,  +1}},

            {{+1, 0}, {+1, -1}, {0,  -1},
                    {-1, 0}, {0,  +1}, {+1, +1}},
    };
    std::vector<Point> result;
    for (auto& i: directions[p.y % 2]) {
        result.emplace_back(p.x + i.x, p.y + i.y);
    }
    return result;
}

bool MapController::attackUnit(const std::shared_ptr<Unit>& unit, const std::shared_ptr<Unit>& other_unit) {
    std::shared_ptr<BattleUnit> battle_unit = std::dynamic_pointer_cast<BattleUnit>(unit);
    std::shared_ptr<BattleUnit> other_battle_unit = std::dynamic_pointer_cast<BattleUnit>(other_unit);

    if (battle_unit && other_battle_unit) {
        return battle_unit->attack(other_battle_unit);
    }

    return false;
}

void MapController::setTurn(int _turn) {
    turn = _turn;
    deselectUnit();
}

unsigned int MapController::movementCost(Point from, Point to) const {
    if (!isInBounds(from) || !isInBounds(to))
        return std::numeric_limits<unsigned int>::max();
    auto neighbours = getNeighbours(from);
    if (std::find(neighbours.begin(), neighbours.end(), to) == neighbours.end())
        //throw std::invalid_argument("From an to are not neighbours!");
        return std::numeric_limits<unsigned int>::max();

    auto fromType = map->getCell(from)->type;
    auto toType = map->getCell(to)->type;
    if ((fromType == Cell::WATER || fromType == Cell::DEEPWATER) ^ (toType == Cell::WATER || toType == Cell::DEEPWATER))
        return std::numeric_limits<unsigned int>::max();

    if ((fromType == Cell::MOUNTAIN) ^ (toType == Cell::MOUNTAIN))
        return std::numeric_limits<unsigned int>::max();

    std::unordered_map<std::pair<Cell::Type, Cell::Type>, unsigned int> distances = {
            {{Cell::PLAIN,     Cell::PLAIN},     1},
            {{Cell::DESERT,    Cell::DESERT},    1},
            {{Cell::HILL,      Cell::HILL},      1},
            {{Cell::WATER,     Cell::WATER},     1},
            {{Cell::DEEPWATER, Cell::DEEPWATER}, 1},
            {{Cell::DEEPWATER, Cell::WATER},     1},
            {{Cell::WATER,     Cell::DEEPWATER}, 1},
            {{Cell::PLAIN,     Cell::DESERT},    1},
            {{Cell::DESERT,    Cell::PLAIN},     1},
            {{Cell::HILL,      Cell::PLAIN},     1},
            {{Cell::PLAIN,     Cell::HILL},      2},
            {{Cell::HILL,      Cell::DESERT},    1},
            {{Cell::DESERT,    Cell::HILL},      2},
    };
    return distances[{fromType, toType}];
}

bool MapController::isInBounds(Point p) const {
    return (p.x >= 0 && p.y >= 0 && p.x < map->size().second && p.y < map->size().first);
}

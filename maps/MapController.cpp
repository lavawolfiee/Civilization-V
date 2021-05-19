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
    if (x < 0 || y < 0 || x >= map->size().second || y >= map->size().first) return;
    auto cell = map->getCell(x, y);
    if (cell->hasUnit()) {
        selectUnit(std::move(cell->getUnit()));
        selectedUnitArea = generateMovementArea({x, y}, selectedUnit->getMovePoints());
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
}

void MapController::render(std::shared_ptr<Batch> batch) {
    const double hexagonSize = 100;
    auto& field = map->getField();
    std::shared_ptr<Batch> cellBatch = std::make_shared<Batch>(*batch);
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            //if(selected == std::make_pair(j, i))
            //    field.at(i).at(j).focus();

            cellBatch->update(batch, j * (Cell::SIZE * sqrt(3) / 2.0) +
                                     (i % 2) * Cell::SIZE * sqrt(3) / 4.0,
                              i * Cell::SIZE * 3 / 4);

            if(selectedUnitArea.isIn(j, i))
                field.at(i).at(j)->render(cellBatch, Cell::SELECTED);
            else
                field.at(i).at(j)->render(cellBatch, Cell::NO_EFFECT);
            //field.at(i).at(j)->unfocus();
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

    std::queue< Point > queue;
    queue.push(p);
    while (!queue.empty()) {
        if(area.size() > 20) break;
        auto v = queue.front();
        queue.pop();
        if (v.x < 0 || v.y < 0 || v.x >= map->size().second || v.y >= map->size().first) continue;
        if(area.isIn(v)) continue;
        area.addCell(v);
        auto neighbours = getNeighbours(v);
        for(auto& i: neighbours) queue.push(i);
    }
    return area;
}

std::vector<Point > MapController::getNeighbours(Point p) {
    std::vector< std::vector< Point > > directions = {
            {{+1, 0},{0, -1},{-1, -1},
            {-1, 0},{-1, +1},{0, +1}},

            {{+1, 0},{+1, -1},{0, -1},
            {-1, 0},{0, +1},{+1, +1}},
    };
    std::vector< Point > result;
    for(auto& i: directions[p.y % 2]) {
        result.emplace_back(p.x + i.x, p.y + i.y);
    }
    return result;
}

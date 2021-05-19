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
    if(x < 0 || y < 0 || x >= map->size().second || y >= map->size().first) return;

    auto cell = map->getCell(x, y);
    if(cell->hasUnit()) {
        auto unit = cell->getUnit();

        if (unit->getPlayer()->getNumber() == turn) {
            selectUnit(std::move(unit));
        } else if (selectedUnit) {
            bool died = attackUnit(selectedUnit, unit);

            if (died)
                moveUnit(selectedUnit, x, y);
        }
    } else if(selectedUnit) {
        moveUnit(selectedUnit, x, y);
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
            field.at(i).at(j)->render(cellBatch);
            field.at(i).at(j)->unfocus();
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
}

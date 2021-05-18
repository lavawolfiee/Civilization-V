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
    auto cell = map->getCell(x, y);
    if(cell.hasUnit()) {
        selectUnit(cell.getUnit());
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
            field.at(i).at(j).render(cellBatch);
            field.at(i).at(j).unfocus();
        }
    }

}

std::shared_ptr<const Map> MapController::getMap() const {
    return map;
}

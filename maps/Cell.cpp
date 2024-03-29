#include "Cell.h"

Cell::Cell(Cell::Type type, int x, int y): type(type), point(x, y) {

}

void Cell::setUnit(std::shared_ptr<Unit> unit) {
    this->unit = std::move(unit);
    this->unit->setCell(shared_from_this());
}

void Cell::render(std::shared_ptr<Batch> batch) {
    render(std::move(batch), {});
}

void Cell::render(std::shared_ptr<Batch> batch, Effects effects) {
    Color c;
    switch (type) {
        case Cell::DEEPWATER:
            c = Color(13, 71, 161);
            break;
        case Cell::WATER:
            c = Color(0, 188, 212);
            break;
        case Cell::PLAIN:
            c = Color(139, 195, 74);
            break;
        case Cell::HILL:
            c = Color(56, 142, 60);
            break;
        case Cell::MOUNTAIN:
            c = Color(158, 158, 158);
            break;
        case Cell::DESERT:
            c = Color(255, 238, 88);
            break;
    }

    batch->fillHexagon(0, 0, SIZE / 2, c,
                       1, Color(0, 0, 0));

    if(effects & SELECTED)
        batch->fillHexagon(0, 0, SIZE / 2, Color(0, 0, 255, 50));

    if (building)
        building->render(batch);

    if (unit)
        unit->render(batch);
}

Cell::Cell(const Cell &cell) {
    type = cell.type;
    building = cell.building;
    unit = cell.unit;
}

bool Cell::hasBuilding() const {
    return static_cast<bool>(building);
}

bool Cell::hasUnit() const {
    return static_cast<bool>(unit);
}

std::shared_ptr<Building> Cell::getBuilding() {
    return building;
}

std::shared_ptr<Unit> Cell::getUnit() {
    return unit;
}

void Cell::eraseUnit() {
    unit = nullptr;
}

const Point& Cell::getPoint() const {
    return point;
}

Cell::~Cell() = default;

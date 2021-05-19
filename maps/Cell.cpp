#include "Cell.h"

Cell::Cell(Cell::Type type): type(type), focused(false) {

}

void Cell::setUnit(std::shared_ptr<Unit> unit) {
    this->unit = std::move(unit);
    this->unit->setCell(shared_from_this());
}

void Cell::render(std::shared_ptr<Batch> batch) {
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

    if(focused)
        batch->fillHexagon(0, 0, SIZE / 2, Color(0, 0, 255, 50));

    if (building)
        building->render(batch);

    if (unit)
        unit->render(batch);
}

Cell::Cell(const Cell &cell) {
    type = cell.type;
    building = std::move(cell.building);
    unit = std::move(cell.unit);
    focused = cell.focused;
}

void Cell::focus() {
    focused = true;
}

void Cell::unfocus() {
    focused = false;
}

std::shared_ptr<Unit> Cell::getUnit() {
    return unit;
}

bool Cell::hasUnit() const {
    return unit != nullptr;
}

void Cell::eraseUnit() {
    unit = nullptr;
}

Cell::~Cell() = default;

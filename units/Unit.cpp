#include "Unit.h"

#include <utility>

void Unit::setCell(std::weak_ptr<Cell> newCell) {
    currentCell = std::move(newCell);
}

std::shared_ptr<Cell> Unit::getCell() {
    if(auto spt = currentCell.lock()) {
        return spt;
    }
    throw std::out_of_range("Empty cell");
}

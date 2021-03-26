#include "Unit.h"
#include <utility>

void Unit::setCell(std::weak_ptr<Cell> newCell) {
    currentCell = std::move(newCell);
}
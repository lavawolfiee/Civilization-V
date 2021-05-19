#include "MovementArea.h"

void MovementArea::addCell(int x, int y) {
    area.emplace(x, y);
}

void MovementArea::addCell(Point p) {
    area.insert(p);
}

bool MovementArea::isIn(Point p) const {
    return (area.find(p) != area.end());
}

bool MovementArea::isIn(int x, int y) const {
    return isIn({x, y});
}

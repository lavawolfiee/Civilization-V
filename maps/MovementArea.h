#ifndef CIVILIZATION_V_MOVEMENTAREA_H
#define CIVILIZATION_V_MOVEMENTAREA_H

#include <unordered_set>

#include "Utilities.h"

class MovementArea {
private:
    std::unordered_set<Point> area;

public:

    MovementArea() : area() {};

    void addCell(Point p);

    void addCell(int x, int y);

    bool isIn(Point p) const;
    bool isIn(int x, int y) const;

    size_t size() const { return area.size(); };
};


#endif //CIVILIZATION_V_MOVEMENTAREA_H

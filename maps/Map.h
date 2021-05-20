#ifndef CIVILIZATION_V_MAP_H
#define CIVILIZATION_V_MAP_H

#include "Cell.h"
#include "../gui/Renderable.h"
#include "../units/Factory.h"

#include "Utilities.h"

#include <cmath>
#include <iostream>
#include <vector>

class Map {
protected:
    size_t width, height;
    std::vector<std::vector<std::shared_ptr<Cell>>> field;

public:
    Map(size_t width, size_t height);
    std::vector<std::vector<std::shared_ptr<Cell>>>& getField() { return field; }
    void setCell(size_t x, size_t y, std::shared_ptr<Cell> cell);

    std::shared_ptr<const Cell> getCell(int x, int y) const;
    std::shared_ptr<Cell> getCell(int x, int y);
    std::shared_ptr<const Cell> getCell(Point p) const;
    std::shared_ptr<Cell> getCell(Point p);

    std::pair< size_t, size_t > size() const;
};

#endif //CIVILIZATION_V_MAP_H

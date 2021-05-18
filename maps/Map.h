#ifndef CIVILIZATION_V_MAP_H
#define CIVILIZATION_V_MAP_H


#include <vector>
#include "Cell.h"
#include "../gui/Renderable.h"
#include "../units/Factory.h"
#include <cmath>

#include <iostream>

class Map {
protected:
    size_t width, height;
    std::vector<std::vector<Cell>> field;

    std::pair< size_t, size_t > selected;

public:
    Map(size_t width, size_t height);
    std::vector<std::vector<Cell>>& getField() { return field; }
    void setCell(size_t x, size_t y, const Cell& cell);
    const Cell& getCell(size_t x, size_t y) const;

    void selectCell(size_t x, size_t y);
};

#endif //CIVILIZATION_V_MAP_H

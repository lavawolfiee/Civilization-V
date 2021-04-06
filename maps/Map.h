#ifndef CIVILIZATION_V_MAP_H
#define CIVILIZATION_V_MAP_H


#include <vector>
#include "Cell.h"
#include "../gui/Renderable.h"
#include "../units/Factory.h"
#include <cmath>

class Map: public Renderable {
protected:
    size_t width, height;
    std::vector<std::vector<Cell>> field;

public:
    Map(size_t width, size_t height);
    const std::vector<std::vector<Cell>>& getField() const { return field; }
    void setCell(size_t x, size_t y, const Cell& cell);
    void render(std::shared_ptr<Batch> batch) override;
};

#endif //CIVILIZATION_V_MAP_H

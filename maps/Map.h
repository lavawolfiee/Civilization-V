#ifndef CIVILIZATION_V_MAP_H
#define CIVILIZATION_V_MAP_H


#include <vector>
#include "../Cell.h"
#include "../Renderable.h"
#include <cmath>

class Map: public Renderable {
protected:
    std::vector<std::vector<Cell>> field;

public:
    const std::vector<std::vector<Cell>>& getField() const { return field; }
    void render(GUI* gui) override;
};

#endif //CIVILIZATION_V_MAP_H

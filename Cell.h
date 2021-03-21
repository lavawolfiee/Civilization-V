#ifndef CIVILIZATION_V_CELL_H
#define CIVILIZATION_V_CELL_H

#include "Renderable.h"
#include "units/Unit.h"
#include "buildings/Building.h"
#include <vector>

class Cell: public Renderable {
private:
    std::vector<Building*> buildings;
    std::vector<Unit*> units;

public:
    enum Type {
        PLAIN,
        HILL,
        MOUNTAIN,
        WATER,
        DESERT
    };

    Type type;

    Cell(Type type);
    void render(GUI* gui) override;
};


#endif //CIVILIZATION_V_CELL_H

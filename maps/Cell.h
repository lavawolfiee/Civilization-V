#ifndef CIVILIZATION_V_CELL_H
#define CIVILIZATION_V_CELL_H

#include "../gui/Renderable.h"
#include "../units/Unit.h"
#include "../buildings/Building.h"
#include <vector>

class Cell: public Renderable {
private:
    std::vector<Building*> buildings;
    std::vector<Unit*> units;

public:
    constexpr const static double SIZE = 50;

    enum Type {
        PLAIN,
        HILL,
        MOUNTAIN,
        WATER,
        DESERT
    };

    Type type;

    Cell(Type type);
    void setUnit(Unit* unit);
    void render(Batch batch) override;
};

#endif //CIVILIZATION_V_CELL_H

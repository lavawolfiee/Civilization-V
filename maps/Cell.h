#ifndef CIVILIZATION_V_CELL_H
#define CIVILIZATION_V_CELL_H

#include "../gui/Renderable.h"
#include "../units/Unit.h"
#include "../buildings/Building.h"

#include <vector>
#include <iostream>

class Cell: public Renderable, public std::enable_shared_from_this<Cell> {
private:
    std::shared_ptr<Building> building;
    std::shared_ptr<Unit> unit;

    bool focused;

public:
    constexpr const static double SIZE = 50;

    enum Type {
        PLAIN,
        HILL,
        MOUNTAIN,
        DEEPWATER,
        WATER,
        DESERT
    };

    Type type;

    Cell(Type type);
    Cell(const Cell& cell);
    ~Cell();

    void setUnit(std::shared_ptr<Unit> unit);
    void eraseUnit();
    void render(std::shared_ptr<Batch> batch) override;

    void focus();
    void unfocus();

    bool hasBuilding() const;
    bool hasUnit() const;

    std::shared_ptr<Building> getBuilding();
    std::shared_ptr<Unit> getUnit();
};

#endif //CIVILIZATION_V_CELL_H

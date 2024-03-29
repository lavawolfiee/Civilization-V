#ifndef CIVILIZATION_V_CELL_H
#define CIVILIZATION_V_CELL_H

#include "../gui/Renderable.h"
#include "../units/Unit.h"
#include "../buildings/Building.h"
#include "Utilities.h"

#include <vector>
#include <iostream>


class Cell: public Renderable, public std::enable_shared_from_this<Cell> {
private:
    std::shared_ptr<Building> building;
    std::shared_ptr<Unit> unit;
    Point point;

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

    enum Effects {
        NO_EFFECT = 0,
        SELECTED = 0b1
    };

    Type type;

    Cell(Type type, int x, int y);
    Cell(const Cell& cell);
    ~Cell();

    void setUnit(std::shared_ptr<Unit> unit);
    void eraseUnit();
    void render(std::shared_ptr<Batch> batch) override;
    void render(std::shared_ptr<Batch> batch, Effects effects);

    bool hasBuilding() const;
    bool hasUnit() const;

    std::shared_ptr<Building> getBuilding();
    std::shared_ptr<Unit> getUnit();

    const Point& getPoint() const;
};

#endif //CIVILIZATION_V_CELL_H

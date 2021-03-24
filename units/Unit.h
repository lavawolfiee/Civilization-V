#ifndef CIVILIZATION_V_UNIT_H
#define CIVILIZATION_V_UNIT_H

#ifdef debug
#include <iostream>
using std::cout;
using std::endl;
#endif

#include "../gui/Renderable.h"
#include "../buildings/Building.h"
#include <vector>

class Cell;

class Unit: public Renderable {
protected:
    Cell* currentCell;
    unsigned int movePoints;
    explicit Unit(unsigned int movePoints) : movePoints(movePoints), currentCell(nullptr) {};
public:
    void setCell(Cell* newCell);
};

class BattleUnit: public Unit {
protected:
    int maxHealth;
    int currentHealth;
    unsigned int strength;
    unsigned int attackRange;
    BattleUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
        Unit(movePoints),
        maxHealth(maxHealth),
        currentHealth(maxHealth),
        strength(strength),
        attackRange(attackRange)
    {};
};

class RangeUnit: public BattleUnit {
private:
    unsigned int strengthRange;
public:
    RangeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange, unsigned int strengthRange) :
        BattleUnit(maxHealth, strength, movePoints, attackRange),
        strengthRange(strengthRange)
    {};
    void render(Batch batch) override;
};

class MeleeUnit: public BattleUnit {
public:
    MeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(Batch batch) override;
};

class CavalryUnit: public BattleUnit {
public:
    CavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(Batch batch) override;
};

class WorkerUnit: public Unit {
public:
    explicit WorkerUnit(unsigned int movePoints) : Unit(movePoints) {};
    void render(Batch batch) override;
};

#endif //CIVILIZATION_V_UNIT_H

#ifndef CIVILIZATION_V_UNIT_H
#define CIVILIZATION_V_UNIT_H

#ifdef debug
#include <iostream>
using std::cout;
using std::endl;
#endif

#include "../gui/Renderable.h"
#include "../buildings/Building.h"
#include "../Player.h"

#include <vector>
#include <iostream>

class Cell;

class Unit: public Renderable {
protected:
    std::weak_ptr<Cell> currentCell;
    std::shared_ptr<Player> player;
    unsigned int movePoints;
    explicit Unit(unsigned int movePoints) : movePoints(movePoints) {};
public:
    void setCell(std::weak_ptr<Cell> newCell);
    std::shared_ptr<Cell> getCell();
    std::shared_ptr<Player> getPlayer();
    void setPlayer(std::shared_ptr<Player> player);

    void die();
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

public:
    bool applyDamage(int damage);
    bool attack(const std::shared_ptr<BattleUnit>& other_unit);
};

class PieceUnit: public Unit {
protected:
    explicit PieceUnit(unsigned int movePoints) :
        Unit(movePoints)
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
};

class MeleeUnit: public BattleUnit {
public:
    MeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, strength, movePoints, attackRange)
    {};
};

class CavalryUnit: public BattleUnit {
public:
    CavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, strength, movePoints, attackRange)
    {};
};

class WorkerUnit: public PieceUnit {
public:
    explicit WorkerUnit(unsigned int movePoints) : PieceUnit(movePoints) {};
};

class SettlerUnit: public PieceUnit {
public:
    explicit SettlerUnit(unsigned int movePoints) : PieceUnit(movePoints) {};
};

#endif //CIVILIZATION_V_UNIT_H

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

    unsigned int getMovePoints() const { return movePoints; };

    void die();
};

class BattleUnit: public Unit {
protected:
    int maxHealth;
    int health;
    unsigned int damage;
    unsigned int attackRange;

    BattleUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange) :
        Unit(movePoints),
        maxHealth(maxHealth),
        health(maxHealth),
        damage(damage),
        attackRange(attackRange)
    {};

public:
    virtual bool applyDamage(int damage);
    virtual bool attack(const std::shared_ptr<BattleUnit>& other_unit);
};

class PieceUnit: public Unit {
protected:
    explicit PieceUnit(unsigned int movePoints) :
        Unit(movePoints)
    {};
};

class RangeUnit: public BattleUnit {
private:
    unsigned int damageRange;
public:
    RangeUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange, unsigned int damageRange) :
        BattleUnit(maxHealth, damage, movePoints, attackRange),
        damageRange(damageRange)
    {};

    bool attack(const std::shared_ptr<BattleUnit>& other_unit) override;
};

class MeleeUnit: public BattleUnit {
public:
    MeleeUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, damage, movePoints, attackRange)
    {};
};

class CavalryUnit: public BattleUnit {
public:
    CavalryUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange) :
            BattleUnit(maxHealth, damage, movePoints, attackRange)
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

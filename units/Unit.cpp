#include "Unit.h"
#include "../maps/Cell.h"

#include <utility>

void Unit::setCell(std::weak_ptr<Cell> newCell) {
    currentCell = std::move(newCell);
}

std::shared_ptr<Cell> Unit::getCell() {
    if(auto spt = currentCell.lock()) {
        return spt;
    }
    throw std::out_of_range("Empty cell");
}

std::shared_ptr<Player> Unit::getPlayer() {
    return player;
}

void Unit::die() {
    if (std::shared_ptr<Cell> spt = currentCell.lock()) {
        spt->eraseUnit();
    }
}

void Unit::setPlayer(std::shared_ptr<Player> _player) {
    player = std::move(_player);
}

bool BattleUnit::applyDamage(int damage) {
    health -= damage;

    if (health <= 0) {
        die();
        return true;
    }

    return false;
}

bool BattleUnit::attack(const std::shared_ptr<BattleUnit>& other_unit) {
    unsigned int dist = hexDistance(getCell()->getPoint(), other_unit->getCell()->getPoint());

    if (dist <= attackRange) {
        // melee attack
        return other_unit->applyDamage(damage);
    }

    return false;
}

bool RangeUnit::attack(const std::shared_ptr<BattleUnit>& other_unit) {
    unsigned int dist = hexDistance(getCell()->getPoint(), other_unit->getCell()->getPoint());

    if (dist <= 1) {
        // melee attack
        return other_unit->applyDamage(damage);
    } else if (dist <= attackRange) {
        // range attack
        other_unit->applyDamage(damageRange);
        return false;
    }

    return false;
}

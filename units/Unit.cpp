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
    currentHealth -= damage;

    if (currentHealth <= 0) {
        die();
        return true;
    }

    return false;
}

bool BattleUnit::attack(const std::shared_ptr<BattleUnit>& other_unit) {
    return other_unit->applyDamage(strength);
}

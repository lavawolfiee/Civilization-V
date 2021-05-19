#include "Player.h"

Player::Player(int number): number(number) {}

int Player::getNumber() const {
    return number;
}

bool Player::operator==(const Player& other) const {
    return (number == other.number);
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}
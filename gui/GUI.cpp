#include "GUI.h"

#include <utility>
#include "../Game.h"

void GUI::setGame(std::weak_ptr<Game> game) {
    this->game = std::move(game);
}

GUI::GUI(): mouse(width / 2, height / 2) {}

GUI::~GUI() = default;
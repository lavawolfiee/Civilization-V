#include "GUI.h"
#include "../Game.h"

void GUI::setGame(Game *game) {
    this->game = game;
}

GUI::GUI(): mouse(width / 2, height / 2) { }
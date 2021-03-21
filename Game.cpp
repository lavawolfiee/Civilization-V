#include "Game.h"
#include "GUI.h"

void Game::loop() {
    while (gui->isOpen()) {
        gui->pollEvents();
        gui->clear({129, 212, 250});
        map->render(gui);
        // gui->fillHexagon(x, y, 100, Color("red"), 3);
        gui->display();
    }
}

Game::Game(GUI *gui, Map* map): gui(gui), map(map) {
    gui->setGame(this);
}

void Game::onMousePressed(int x, int y) {
    pressed = true;
}

void Game::onMouseReleased(int x, int y) {
    pressed = false;
}

void Game::onMouseMoved(int x, int y) {
    if (pressed) {
        this->x = x;
        this->y = y;
    }
}

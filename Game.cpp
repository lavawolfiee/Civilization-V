#include "Game.h"
#include "gui/GUI.h"
#include <iostream>

void Game::loop() {
    double x = 0, y = 0;
    while (gui->isOpen()) {
        gui->pollEvents();
        gui->clear({129, 212, 250});
        map->render(new BatchGUI(gui, x, y));
        // gui->fillHexagon(x, y, 100, Color("red"), 3);
        gui->display();
//        x += 0.1;
//        y += 0.2;
    }
}

Game::Game(GUI *gui, Map* map): gui(gui), map(map) {
    gui->setGame(this);
}

void Game::onMousePressed(int x, int y) {
}

void Game::onMouseReleased(int x, int y) {
}

void Game::onMouseMoved(int x, int y) {
}

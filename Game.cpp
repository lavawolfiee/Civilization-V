#include "Game.h"
#include "gui/GUI.h"
#include <iostream>

void Game::loop() {
    double cameraVelocity = 500;
    gui->delta();
    while (gui->isOpen()) {
        delta = gui->delta();
        gui->pollEvents();

        if (mouseX <= 0.025 * gui->width)
            mapX += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouseX >= 0.975 * gui->width)
            mapX -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        if (mouseY <= 0.025 * gui->height)
            mapY += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouseY >= 0.975 * gui->height)
            mapY -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        gui->clear({129, 212, 250});
        map->render(new BatchGUI(gui, mapX, mapY));
        gui->display();
    }
}

Game::Game(GUI *gui, Map* map): gui(gui), map(map), delta(0), mapX(0.0), mapY(0.0), mouseX(gui->width / 2),
                                mouseY(gui->height / 2), mousePressed(false), pressX(0), pressY(0) {
    gui->setGame(this);
}

void Game::onMousePressed(int x, int y) {
    mousePressed = true;
    pressX = x;
    pressY = y;
}

void Game::onMouseReleased(int x, int y) {
    if (mousePressed && pressX == x && pressY == y) {
        mousePressed = false;
        onMouseClicked(x, y);
    }

    mousePressed = false;
}

void Game::onMouseMoved(int x, int y) {
    mouseX = x;
    mouseY = y;
}

void Game::onMouseClicked(int x, int y) {

}

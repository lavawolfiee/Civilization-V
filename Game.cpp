#include "Game.h"
#include "gui/GUI.h"
#include <cmath>

void Game::loop() {

    double cameraVelocity = 500;
    gui->delta();
    while (gui->isOpen()) {
        delta = gui->delta();
        const Mouse& mouse = gui->mouse;
        gui->pollEvents();

        if (mouse.x <= 0.025 * gui->width)
            mapX += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouse.x >= 0.975 * gui->width)
            mapX -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        if (mouse.y <= 0.025 * gui->height)
            mapY += cameraVelocity * static_cast<double>(delta) / 1'000'000;
        else if (mouse.y >= 0.975 * gui->height)
            mapY -= cameraVelocity * static_cast<double>(delta) / 1'000'000;

        gui->clear({129, 212, 250});
        double x = gui->width / 2 - mapX, y = gui->height / 2 - mapY;
        map->render(new Batch(new Batch(new BatchGUI(gui, mapX, mapY), x, y, (zoom >= 1.0 ? tanh(zoom) * 1.5 : tanh(zoom) * (1.0 - 1.0 / 8.0)) + 1), -x, -y));
        gui->display();
    }
}

Game::Game(GUI *gui, Map* map): gui(gui), map(map), delta(0), mapX(0.0), mapY(0.0), zoom(0.0) {
    gui->setGame(this);
}

void Game::onMousePressed(int x, int y) {}

void Game::onMouseReleased(int x, int y) {}

void Game::onMouseMoved(int x, int y) {}

void Game::onMouseClicked(int x, int y) {}

void Game::onMouseWheelScrolled(double scrollDelta) {
    zoom += scrollDelta / 4;
    zoom = fmin(5.0, fmax(-5.0, zoom));
}

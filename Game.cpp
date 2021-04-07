#include "Game.h"
#include "gui/GUI.h"
#include <cmath>
#include <memory>
#include <utility>

void Game::loop() {

    double cameraVelocity = 500;
    gui->delta();
    while (gui->isOpen()) {
        delta = gui->delta();
        const Mouse &mouse = gui->mouse;
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
        map->render(std::make_shared<Batch>(std::make_shared<Batch>(std::make_shared<BatchGUI>(gui, mapX, mapY), x, y,
                                                                    (zoom >= 0.0 ? tanh(zoom) * 1.5 : tanh(zoom) / 2) +
                                                                    1), -x, -y));
        gui->display();
    }
}

Game::Game() : delta(0), mapX(0.0), mapY(0.0), zoom(0.0) {

}

void Game::onMousePressed(int x, int y) {}

void Game::onMouseReleased(int x, int y) {}

void Game::onMouseMoved(int x, int y) {}

void Game::onMouseClicked(int x, int y) {}

void Game::onMouseWheelScrolled(double scrollDelta) {
    zoom += scrollDelta / 4;
    zoom = fmin(5.0, fmax(-5.0, zoom));
}

void Game::setGUI(std::shared_ptr<GUI> gui) {
    this->gui = std::move(gui);
    this->gui->setMousePressedListener(std::bind(&Game::onMousePressed, this,
                                                 std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseReleasedListener(std::bind(&Game::onMouseReleased, this,
                                                  std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseMovedListener(std::bind(&Game::onMouseMoved, this,
                                               std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseClickedListener(std::bind(&Game::onMouseClicked, this,
                                                 std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseWheelScrolledListener(std::bind(&Game::onMouseWheelScrolled, this,
                                                       std::placeholders::_1));
}

void Game::setMap(std::shared_ptr<Map> map) {
    this->map = std::move(map);
}

Game::~Game() = default;

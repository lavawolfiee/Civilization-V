#include "Game.h"
#include "gui/GUI.h"
#include <cmath>
#include <memory>
#include <utility>

void Game::loop() {

    double cameraVelocity = 500;
    gui->delta();
    /*double x = 0;
    double y = 0;*/
    while (gui->isOpen()) {
        //map->selectCell(x, y);
        delta = gui->delta();

        /*x += delta / 1000000.0;
        if(x >= 20) {
            x = 0;
            ++y;
        }*/

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
        map->render(std::make_shared<Batch>(std::make_shared<Batch>(std::make_shared<BatchGUI>(gui, mapX, mapY), x, y, getMapScale()), -x, -y));
        gui->display();
    }
}

Game::Game() : delta(0), mapX(0.0), mapY(0.0), zoom(0.0), turn(0) {

}

void Game::onMousePressed(int x, int y) {}

void Game::onMouseReleased(int x, int y) {}

void Game::onMouseMoved(int x, int y) {
    double scale = getMapScale();
    double cellSize = Cell::SIZE * scale / 2;
    double xOnMap = x - (mapX - gui->width / 2) * scale - gui->width / 2 - cellSize;
    double yOnMap = y - (mapY - gui->height / 2) * scale - gui->height / 2 - cellSize;
    int cellX = floor((xOnMap / sqrt(3) - yOnMap / 3.0) / cellSize + 0.5);
    int cellY = floor(2.0 * yOnMap / 3.0 / cellSize + 0.5);
    map->selectCell(cellX + cellY / 2, cellY);
}

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
    this->gui->createButton("End turn", {"72.5%", "90%"}, {"25%", "3%"},
                            std::bind(&Game::nextTurn, std::ref(*this)));
}

void Game::setMap(std::shared_ptr<Map> map) {
    this->map = std::move(map);
}

void Game::nextTurn() {
    std::cout << turn << std::endl;
    if(players.empty()) return;
    ++turn;
    turn %= players.size();
}

double Game::getMapScale() {
    return (zoom >= 0.0 ? tanh(zoom) * 1.5 : tanh(zoom) / 2) + 1;
}

Game::~Game() = default;

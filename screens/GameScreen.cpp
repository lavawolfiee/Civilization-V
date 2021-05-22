#include "GameScreen.h"

GameScreen::GameScreen(int playersCount) : mapX(0.0), mapY(0.0), zoom(0.0), turn(0), cameraVelocity(500) {
    StandardMapGenerator mapGenerator;
    mapController = std::make_shared<MapController>();
    mapController->setMap(mapGenerator.generateMap());

    players.reserve(playersCount);

    for (int i = 0; i < playersCount; ++i)
        players.push_back(std::make_shared<Player>(i));

    AncientUnitFactory factory;
    std::shared_ptr<Unit> unit = factory.createUnit(UnitFactory::UnitType::MELEE);
    unit->setPlayer(players.at(0));
    mapController->addUnit(10, 10, unit);

    ClassicalUnitFactory factory2;
    std::shared_ptr<Unit> unit2 = factory2.createUnit(UnitFactory::UnitType::RANGE);
    unit2->setPlayer(players.at(1));
    mapController->addUnit(20, 20, unit2);
}

void GameScreen::onMouseReleased(int x, int y) {
    auto cellCoord = getMouseMapCoord();
    mapController->onCellClicked(cellCoord.first, cellCoord.second);
}

void GameScreen::onMouseMoved(int x, int y) {
    auto cellCoord = getMouseMapCoord();
    //mapController->selectCell(cellCoord.first, cellCoord.second);
}

void GameScreen::onMouseWheelScrolled(double scrollDelta) {
    zoom += scrollDelta / 4;
    zoom = fmin(5.0, fmax(-5.0, zoom));
}

void GameScreen::recreateUI() {
    this->gui->createButton("End turn", {"72.5%", "90%"}, {"25%", "3%"},
                            [&capture = *this] { capture.nextTurn(); });
}

void GameScreen::nextTurn() {
    std::cout << turn << std::endl;
    if (players.empty()) return;
    ++turn;
    turn %= players.size();
    mapController->setTurn(turn);
}

double GameScreen::getMapScale() const {
    return (zoom >= 0.0 ? tanh(zoom) * 1.5 : tanh(zoom) / 2) + 1;
}

std::pair<int, int> GameScreen::getMouseMapCoord() const {
    double x = gui->mouse.x, y = gui->mouse.y;
    double scale = getMapScale();
    double cellSize = Cell::SIZE * scale / 2;
    double xOnMap = x - (mapX - gui->width / 2) * scale - gui->width / 2 - cellSize;
    double yOnMap = y - (mapY - gui->height / 2) * scale - gui->height / 2 - cellSize;
    return MapController::convertGlobalToMapCoord(xOnMap / cellSize, yOnMap / cellSize);
}

void GameScreen::Tick(unsigned long long int delta) {
    if(!gui) return;
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
    mapController->render(std::make_shared<Batch>(
            std::make_shared<Batch>(std::make_shared<BatchGUI>(gui, mapX, mapY), x, y, getMapScale()), -x, -y));
}

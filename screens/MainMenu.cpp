#include "MainMenu.h"

MainMenu::MainMenu() {}

void MainMenu::recreateUI() {
    this->gui->createButton("Start Game", {"42.5%", "35%"}, {"15%", "5%"},
                       [] { ScreensManager::getInstance().setScreen(std::make_shared<GameScreen>()); });
    this->gui->createButton("Map Editor", {"42.5%", "50%"}, {"15%", "5%"},
                       [] { ScreensManager::getInstance().setScreen(std::make_shared<GameScreen>()); });
    this->gui->createButton("Quit", {"42.5%", "65%"}, {"15%", "5%"},
                            [] { throw Quit(); });
}

void MainMenu::Tick(unsigned long long int) {
    if(!gui) return;
    gui->pollEvents();
}



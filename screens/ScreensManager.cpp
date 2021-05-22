#include "ScreensManager.h"

ScreensManager& ScreensManager::getInstance() {
    static ScreensManager instance;
    return instance;
}


ScreensManager::ScreensManager() {
    setGUI(std::make_shared<SfmlGUI>());
}

void ScreensManager::setScreen(std::shared_ptr<Screen> screen) {
    gui->clear();
    this->currentScreen = std::move(screen);
    this->currentScreen->setGui(gui);
}

void ScreensManager::setGUI(std::shared_ptr<GUI> gui) {
    this->gui = std::move(gui);
    this->gui->setMousePressedListener(std::bind(&ScreensManager::onMousePressed, this,
                                                 std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseReleasedListener(std::bind(&ScreensManager::onMouseReleased, this,
                                                  std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseMovedListener(std::bind(&ScreensManager::onMouseMoved, this,
                                               std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseClickedListener(std::bind(&ScreensManager::onMouseClicked, this,
                                                 std::placeholders::_1, std::placeholders::_2));
    this->gui->setMouseWheelScrolledListener(std::bind(&ScreensManager::onMouseWheelScrolled, this,
                                                       std::placeholders::_1));
    if(currentScreen) currentScreen->setGui(gui);
}

void ScreensManager::Tick() {
    if(currentScreen) currentScreen->Tick(gui->delta());
    gui->display();
}

void ScreensManager::onMousePressed(int x, int y) {
    if(currentScreen) currentScreen->onMousePressed(x, y);
}

void ScreensManager::onMouseReleased(int x, int y) {
    if(currentScreen) currentScreen->onMouseReleased(x, y);
}

void ScreensManager::onMouseMoved(int x, int y) {
    if(currentScreen) currentScreen->onMouseMoved(x, y);
}

void ScreensManager::onMouseClicked(int x, int y) {
    if(currentScreen) currentScreen->onMouseClicked(x, y);
}

void ScreensManager::onMouseWheelScrolled(double scrollDelta) {
    if(currentScreen) currentScreen->onMouseWheelScrolled(scrollDelta);
}


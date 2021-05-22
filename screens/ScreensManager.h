#ifndef CIVILIZATION_V_SCREENSMANAGER_H
#define CIVILIZATION_V_SCREENSMANAGER_H

#include "Screen.h"
#include <gui/SfmlGUI.h>

class ScreensManager {
protected:
    //static std::shared_ptr<ScreensManager> instance;

    std::shared_ptr<GUI> gui;
    std::shared_ptr<Screen> currentScreen;

    ScreensManager();

public:

    //static std::shared_ptr<ScreensManager> getInstance();
    static ScreensManager& getInstance();

    void setScreen(std::shared_ptr<Screen> screen);
    void setGUI(std::shared_ptr<GUI> gui);

    void Tick();

    void onMousePressed(int x, int y);
    void onMouseReleased(int x, int y);
    void onMouseMoved(int x, int y);
    void onMouseClicked(int x, int y);
    void onMouseWheelScrolled(double scrollDelta);
};


#endif //CIVILIZATION_V_SCREENSMANAGER_H

#ifndef CIVILIZATION_V_SCREEN_H
#define CIVILIZATION_V_SCREEN_H

#include "gui/GUI.h"

class Screen {
protected:
    std::shared_ptr< GUI > gui;
public:

    void setGui(std::shared_ptr<GUI> gui);
    virtual void recreateUI() {};

    virtual void Tick(unsigned long long delta) = 0;

    virtual void onMousePressed(int x, int y) {};
    virtual void onMouseReleased(int x, int y) {};
    virtual void onMouseMoved(int x, int y) {};
    virtual void onMouseClicked(int x, int y) {};
    virtual void onMouseWheelScrolled(double scrollDelta) {};

    virtual ~Screen() = default;
};


#endif //CIVILIZATION_V_SCREEN_H

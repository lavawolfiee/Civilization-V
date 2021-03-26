#ifndef CIVILIZATION_V_GUI_H
#define CIVILIZATION_V_GUI_H

#include "Color.h"
#include <vector>
#include "Mouse.h"

class Game;

class GUI {
protected:
    Game* game = nullptr;

public:
    int width = 0;
    int height = 0;

    Mouse mouse;

    GUI();

    virtual void display() = 0;
    virtual void clear(Color c = Color("black")) = 0;
    virtual bool isOpen() const = 0;
    virtual void fillCircle(double x, double y, double r, Color c, double borderWidth = 0,
                            Color borderColor = Color("black")) = 0;
    virtual void fillHexagon(double x, double y, double r, Color c, double borderWidth = 0,
                            Color borderColor = Color("black")) = 0;
    virtual void fillTriangle(double x, double y, double a, Color c, double borderWidth = 0,
                             Color borderColor = Color("black")) = 0;

    virtual void pollEvents() = 0;
    virtual void setGame(Game* game);
    virtual unsigned long long delta() = 0;
};

#endif //CIVILIZATION_V_GUI_H
#ifndef CIVILIZATION_V_GUI_H
#define CIVILIZATION_V_GUI_H

#include "Color.h"
#include <vector>
#include <memory>
#include "Mouse.h"
#include <functional>

class GUI {
protected:
    std::function<void(int, int)> mousePressedListener;
    std::function<void(int, int)> mouseReleasedListener;
    std::function<void(int, int)> mouseMovedListener;
    std::function<void(int, int)> mouseClickedListener;
    std::function<void(double)> mouseWheelScrolledListener;

public:
    int width = 0;
    int height = 0;

    Mouse mouse;

    GUI();

    virtual ~GUI();

    virtual void display() = 0;

    virtual void clear(Color c = Color("black")) = 0;
    virtual void removeAllWidgets() = 0;

    virtual bool isOpen() const = 0;

    virtual void fillCircle(double x, double y, double r, Color c, double borderWidth = 0,
                            Color borderColor = Color("black")) = 0;

    virtual void fillHexagon(double x, double y, double r, Color c, double borderWidth = 0,
                             Color borderColor = Color("black")) = 0;

    virtual void fillTriangle(double x, double y, double a, Color c, double borderWidth = 0,
                              Color borderColor = Color("black")) = 0;

    virtual void createButton(std::string text, std::pair<std::string, std::string> position,
                              std::pair<std::string, std::string> size, std::function<void()> callback) = 0;

    virtual void
    createSlider(std::pair<std::string, std::string> position, std::pair<std::string, std::string> size, double step,
                 std::function<void(float)> callback) = 0;

    virtual void setMouseMovedListener(std::function<void(int, int)> listener);
    virtual void setMousePressedListener(std::function<void(int, int)> listener);
    virtual void setMouseReleasedListener(std::function<void(int, int)> listener);
    virtual void setMouseClickedListener(std::function<void(int, int)> listener);
    virtual void setMouseWheelScrolledListener(std::function<void(double)> listener);

    virtual void pollEvents() = 0;

    virtual unsigned long long delta() = 0;
};

#endif //CIVILIZATION_V_GUI_H
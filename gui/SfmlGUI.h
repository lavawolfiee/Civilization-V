#ifndef CIVILIZATION_V_SFMLGUI_H
#define CIVILIZATION_V_SFMLGUI_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "GUI.h"
#include "../Game.h"

class SfmlGUI: public GUI {
private:
    sf::RenderWindow* window;
    sf::Clock clock;

public:
    SfmlGUI();

    void display() override;
    void clear(Color c) override;
    bool isOpen() const override;
    void fillCircle(double x, double y, double r, Color c, double borderWidth = 0,
                    Color borderColor = Color("black")) override;
    void fillHexagon(double x, double y, double r, Color c, double borderWidth = 0,
                     Color borderColor = Color("black")) override;
    void fillTriangle(double x, double y, double a, Color c, double borderWidth = 0,
                     Color borderColor = Color("black")) override;

    void pollEvents() override;
    unsigned long long delta() override;
};


#endif //CIVILIZATION_V_SFMLGUI_H

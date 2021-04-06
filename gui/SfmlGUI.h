#ifndef CIVILIZATION_V_SFMLGUI_H
#define CIVILIZATION_V_SFMLGUI_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>
#include "GUI.h"
#include "../Game.h"

class SfmlGUI : public GUI {
private:
    sf::RenderWindow window;
    sf::Clock clock;

    tgui::Gui gui;

public:
    SfmlGUI();

    ~SfmlGUI() override;

    void display() override;

    void clear(Color c) override;

    bool isOpen() const override;

    void fillCircle(double x, double y, double r, Color c, double borderWidth = 0,
                    Color borderColor = Color("black")) override;

    void fillHexagon(double x, double y, double r, Color c, double borderWidth = 0,
                     Color borderColor = Color("black")) override;

    void fillTriangle(double x, double y, double a, Color c, double borderWidth = 0,
                      Color borderColor = Color("black")) override;

    void createButton(std::string text, std::pair<std::string, std::string> position,
                      std::pair<std::string, std::string> size, std::function<void()> callback) override;

    void
    createSlider(std::pair<std::string, std::string> position, std::pair<std::string, std::string> size, double step,
                 std::function<void(float)> callback) override;

    void pollEvents() override;

    unsigned long long delta() override;
};


#endif //CIVILIZATION_V_SFMLGUI_H

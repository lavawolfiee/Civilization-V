#include "SfmlGUI.h"
#include <SFML/Graphics.hpp>

void SfmlGUI::display() {
    window.display();
}

void SfmlGUI::clear(Color c) {
    window.clear(sf::Color(c.r, c.g, c.b, c.a));
}

SfmlGUI::SfmlGUI(): width(sf::VideoMode::getDesktopMode().width),
                    height(sf::VideoMode::getDesktopMode().height),
                    window(sf::VideoMode(width, height), "Civilization_V", sf::Style::Fullscreen) {

}

void SfmlGUI::fillCircle(double x, double y, double r, Color c, double borderWidth, Color borderColor) {
    sf::CircleShape circle(r);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color(c.r, c.g, c.b, c.a));
    circle.setOutlineThickness(borderWidth);
    circle.setOutlineColor(sf::Color(borderColor.r, borderColor.g, borderColor.b, borderColor.a));
    window.draw(circle);
}

void SfmlGUI::fillHexagon(double x, double y, double r, Color c, double borderWidth, Color borderColor) {
    sf::CircleShape circle(r, 6);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color(c.r, c.g, c.b, c.a));
    circle.setOutlineThickness(borderWidth);
    circle.setOutlineColor(sf::Color(borderColor.r, borderColor.g, borderColor.b, borderColor.a));
    window.draw(circle);
}

bool SfmlGUI::isOpen() const {
    return window.isOpen();
}

void SfmlGUI::pollEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    game->onMousePressed(event.mouseButton.x, event.mouseButton.y);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    game->onMouseReleased(event.mouseButton.x, event.mouseButton.y);
                }
                break;
            case sf::Event::MouseMoved:
                game->onMouseMoved(event.mouseMove.x, event.mouseMove.y);
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

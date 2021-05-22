#include "SfmlGUI.h"
#include <SFML/Graphics.hpp>

void SfmlGUI::display() {
    gui.draw();
    window.display();
}

void SfmlGUI::clear(Color c) {
    window.clear(sf::Color(c.r, c.g, c.b, c.a));
}

void SfmlGUI::removeAllWidgets() {
    gui.removeAllWidgets();
}

SfmlGUI::SfmlGUI() {
    width = sf::VideoMode::getDesktopMode().width;
    height = sf::VideoMode::getDesktopMode().height;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "Civilization_V",
                  sf::Style::Fullscreen, settings);
    gui.setTarget(window);

    //createButton()
    /*auto btn = tgui::Button::create("Regenerate");
    btn->setSize({"5%", "3%"});
    btn->setPosition({"90%", "50%"});
    gui.add(btn);

    auto slider = tgui::Slider::create(0.0, 1.0);
    slider->setSize({"10%", "2%"});
    slider->setPosition({"87.5%", "45%"});
    slider->setStep(0.05);
    gui.add(slider);*/

    //slider->onValueChange(&SfmlGUI::fillCircle, std::ref(*this), 100.0, 100.0);
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
        if(gui.handleEvent(event)) continue;
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mouse.x = event.mouseButton.x;
                    mouse.y = event.mouseButton.y;
                    mouse.pressed = true;
                    mouse.pressX = event.mouseButton.x;
                    mouse.pressX = event.mouseButton.y;
                    if (mousePressedListener)
                        mousePressedListener(event.mouseButton.x, event.mouseButton.y);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    bool wasPressed = mouse.pressed;
                    mouse.x = event.mouseButton.x;
                    mouse.y = event.mouseButton.y;
                    mouse.pressed = false;
                    if (mouseReleasedListener)
                        mouseReleasedListener(event.mouseButton.x, event.mouseButton.y);

                    if (wasPressed && mouse.pressX == mouse.x && mouse.pressY == mouse.y) {
                        mouseClickedListener(mouse.x, mouse.y);
                    }
                }
                break;
            case sf::Event::MouseMoved:
                mouse.x = event.mouseMove.x;
                mouse.y = event.mouseMove.y;
                if (mouseMovedListener)
                    mouseMovedListener(event.mouseMove.x, event.mouseMove.y);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseWheelScrolled:
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                    if (mouseWheelScrolledListener)
                        mouseWheelScrolledListener(event.mouseWheelScroll.delta);
                break;
        }
    }
}

void SfmlGUI::fillTriangle(double x, double y, double a, Color c, double borderWidth, Color borderColor) {
    double r = sqrt(3) * a;
    sf::CircleShape circle(r, 3);
    circle.setPosition(x, y);
    circle.setRotation(180);
    circle.setFillColor(sf::Color(c.r, c.g, c.b, c.a));
    circle.setOutlineThickness(borderWidth);
    circle.setOutlineColor(sf::Color(borderColor.r, borderColor.g, borderColor.b, borderColor.a));
    window.draw(circle);
}

unsigned long long SfmlGUI::delta() {
    return clock.restart().asMicroseconds();
}

void SfmlGUI::createButton(std::string text, std::pair<std::string, std::string> position,
                           std::pair<std::string, std::string> size, std::function<void()> callback) {
    auto btn = tgui::Button::create(text);
    btn->setSize(tgui::Layout(size.first), tgui::Layout(size.second));
    btn->setPosition(tgui::Layout(position.first), tgui::Layout(position.second));
    gui.add(btn);
    btn->onPress(callback);
}

void SfmlGUI::createSlider(std::pair<std::string, std::string> position, std::pair<std::string, std::string> size,
                           double step, std::function<void(float)> callback) {
    auto slider = tgui::Slider::create(0.0, 1.0);
    slider->setSize(tgui::Layout(size.first), tgui::Layout(size.second));
    slider->setPosition(tgui::Layout(position.first), tgui::Layout(position.second));
    slider->setStep(step);
    gui.add(slider);
    slider->onValueChange(callback);
}

SfmlGUI::~SfmlGUI() = default;
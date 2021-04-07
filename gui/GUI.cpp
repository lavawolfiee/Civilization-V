#include "GUI.h"

#include <utility>

GUI::GUI(): mouse(width / 2, height / 2) {}

void GUI::setMouseMovedListener(std::function<void(int, int)> listener) {
    mouseMovedListener = std::move(listener);
}

void GUI::setMousePressedListener(std::function<void(int, int)> listener) {
    mousePressedListener = std::move(listener);
}

void GUI::setMouseReleasedListener(std::function<void(int, int)> listener) {
    mouseReleasedListener = std::move(listener);
}

void GUI::setMouseClickedListener(std::function<void(int, int)> listener) {
    mouseClickedListener = std::move(listener);
}

void GUI::setMouseWheelScrolledListener(std::function<void(double)> listener) {
    mouseWheelScrolledListener = std::move(listener);
}

GUI::~GUI() = default;
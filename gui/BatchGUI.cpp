#include "BatchGUI.h"
#include <iostream>
#include <utility>

BatchGUI::BatchGUI(std::shared_ptr<GUI> gui, double offsetX, double offsetY, double scale, double rotation) : gui(std::move(gui)),
                                                                                Batch(nullptr, offsetX, offsetY, scale,
                                                                                      rotation) {};

void BatchGUI::fillCircle(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!gui) return;
    gui->fillCircle(offsetX + x * scale, offsetY + y * scale, radius * scale, color, borderWidth, borderColor);
}

void BatchGUI::fillHexagon(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!gui) return;
    gui->fillHexagon(offsetX + x * scale, offsetY + y * scale, radius * scale, color, borderWidth, borderColor);
}

void BatchGUI::fillTriangle(double x, double y, double a, Color color, double borderWidth, Color borderColor) const {
    if (!gui) return;
    gui->fillTriangle(offsetX + x * scale, offsetY + y * scale, a * scale, color, borderWidth, borderColor);
}

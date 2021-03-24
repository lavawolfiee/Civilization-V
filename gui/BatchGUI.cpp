#include "BatchGUI.h"
#include <iostream>

BatchGUI::BatchGUI(GUI *gui, double offsetX, double offsetY, double rotation) : gui(gui),
                                                                                Batch(nullptr, offsetX, offsetY,
                                                                                      rotation) {};

void BatchGUI::fillCircle(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!gui) return;
    gui->fillCircle(offsetX + x, offsetY + y, radius, color, borderWidth, borderColor);
}

void BatchGUI::fillHexagon(double x, double y, double radius, Color color, double borderWidth, Color borderColor) const {
    if(!gui) return;
    gui->fillHexagon(offsetX + x, offsetY + y, radius, color, borderWidth, borderColor);
}

void BatchGUI::fillTriangle(double x, double y, double a, Color color, double borderWidth, Color borderColor) const {
    if (!gui) return;
    gui->fillTriangle(offsetX + x, offsetY + y, a, color, borderWidth, borderColor);
}

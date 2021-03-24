#ifndef CIVILIZATION_V_BATCHGUI_H
#define CIVILIZATION_V_BATCHGUI_H

#include "Batch.h"
#include "GUI.h"

class BatchGUI : public Batch {
private:
    GUI* gui;

public:
    BatchGUI(GUI* gui, double offsetX = 0.0, double offsetY = 0.0, double scale = 1.0, double rotation = 0.0);
    void fillCircle(double x, double y, double radius, Color color, double borderWidth = 0, Color borderColor = Color("black")) const override;
    void fillHexagon(double x, double y, double radius, Color color, double borderWidth = 0, Color borderColor = Color("black")) const override;
    void fillTriangle(double x, double y, double a, Color color, double borderWidth = 0, Color borderColor = Color("black")) const override;
};


#endif //CIVILIZATION_V_BATCHGUI_H

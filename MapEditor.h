#ifndef CIVILIZATION_V_MAPEDITOR_H
#define CIVILIZATION_V_MAPEDITOR_H

#include <vector>
#include "maps/Map.h"
#include "gui/Batch.h"
#include "gui/BatchGUI.h"
#include "maps/StandardMapGenerator.h"

class GUI;


class MapEditor {
private:
    std::shared_ptr<GUI> gui;
    StandardMapGenerator mapGenerator;
    std::shared_ptr<Map> map;
    unsigned long long delta;

    double mapX, mapY;
    double zoom;

    StandardMapConfig config;

public:
    MapEditor();
    ~MapEditor() = default;

    void loop();

    void setGUI(std::shared_ptr<GUI> gui);
    void regenerateMap();
    void setFrequency(float freq);
    void setStep(float step);
};


#endif //CIVILIZATION_V_MAPEDITOR_H

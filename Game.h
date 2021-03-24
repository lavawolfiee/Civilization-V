#ifndef CIVILIZATION_V_GAME_H
#define CIVILIZATION_V_GAME_H

#include <vector>
#include "maps/Map.h"
#include "gui/Batch.h"
#include "gui/BatchGUI.h"

class GUI;

class Game {
private:
    GUI* gui;
    Map* map;
    unsigned long long delta;

    double mapX, mapY;
    int mouseX, mouseY;
    bool mousePressed;
    int pressX, pressY;

public:
    Game(GUI* gui, Map* map);

    void loop();

    void onMousePressed(int x, int y);
    void onMouseReleased(int x, int y);
    void onMouseMoved(int x, int y);
    void onMouseClicked(int x, int y);
};


#endif //CIVILIZATION_V_GAME_H

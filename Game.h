#ifndef CIVILIZATION_V_GAME_H
#define CIVILIZATION_V_GAME_H

#include <vector>
#include "maps/Map.h"

class GUI;

class Game {
private:
    GUI* gui;
    Map* map;
    bool pressed = false;
    int x = 0, y = 0;

public:
    Game(GUI* gui, Map* map);

    void loop();

    void onMousePressed(int x, int y);
    void onMouseReleased(int x, int y);
    void onMouseMoved(int x, int y);
};


#endif //CIVILIZATION_V_GAME_H

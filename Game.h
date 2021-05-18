#ifndef CIVILIZATION_V_GAME_H
#define CIVILIZATION_V_GAME_H

#include <vector>
#include "maps/Map.h"
#include "gui/Batch.h"
#include "gui/BatchGUI.h"
#include "Player.h"

#include <iostream>
#include "gui/GUI.h"

class Game: public std::enable_shared_from_this<Game> {
private:
    std::shared_ptr<GUI> gui;
    std::shared_ptr<Map> map;
    unsigned long long delta;

    double mapX, mapY;
    double zoom;

    std::vector< std::shared_ptr< Player > > players;
    unsigned int turn;

    double getMapScale() const;

    std::pair<int, int> xyToCell(int x, int y) const;

public:
    Game(int playersCnt = 2);
    ~Game();

    void loop();

    void onMousePressed(int x, int y);
    void onMouseReleased(int x, int y);
    void onMouseMoved(int x, int y);
    void onMouseClicked(int x, int y);
    void onMouseWheelScrolled(double scrollDelta);

    void setGUI(std::shared_ptr<GUI> gui);
    void setMap(std::shared_ptr<Map> map);

    void nextTurn();
};


#endif //CIVILIZATION_V_GAME_H

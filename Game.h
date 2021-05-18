#ifndef CIVILIZATION_V_GAME_H
#define CIVILIZATION_V_GAME_H

#include "maps/Map.h"
#include "maps/MapController.h"

#include "gui/Batch.h"
#include "gui/BatchGUI.h"
#include "gui/GUI.h"

#include "Player.h"

#include <iostream>
#include <vector>

class Game: public std::enable_shared_from_this<Game> {
private:
    std::shared_ptr<GUI> gui;
    //std::shared_ptr<Map> map;
    std::shared_ptr<MapController> mapController;
    unsigned long long delta;

    double mapX, mapY;
    double zoom;

    std::vector< std::shared_ptr< Player > > players;
    unsigned int turn;

    double getMapScale() const;
    std::pair< int, int > getMouseMapCoord() const;

public:
    Game();
    ~Game();

    void loop();

    void onMousePressed(int x, int y);
    void onMouseReleased(int x, int y);
    void onMouseMoved(int x, int y);
    void onMouseClicked(int x, int y);
    void onMouseWheelScrolled(double scrollDelta);

    void setGUI(std::shared_ptr<GUI> gui);
    void setMapController(std::shared_ptr<MapController> mapController);

    void nextTurn();
};


#endif //CIVILIZATION_V_GAME_H

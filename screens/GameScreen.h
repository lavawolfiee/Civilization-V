#ifndef CIVILIZATION_V_GAMESCREEN_H
#define CIVILIZATION_V_GAMESCREEN_H

#include <gui/BatchGUI.h>
#include "Screen.h"
#include <maps/StandardMapGenerator.h>
#include <maps/MapController.h>

class GameScreen : public Screen {
private:
    std::shared_ptr<MapController> mapController;

    double mapX, mapY;
    double zoom;
    double cameraVelocity;

    std::vector< std::shared_ptr< Player > > players;
    unsigned int turn;

    double getMapScale() const;
    std::pair< int, int > getMouseMapCoord() const;

public:
    GameScreen(int playersCount = 2);

    void nextTurn();

    void recreateUI() override;

    void Tick(unsigned long long delta) override;

    void onMousePressed(int x, int y) override;
    void onMouseReleased(int x, int y) override;
    void onMouseMoved(int x, int y) override;
    void onMouseClicked(int x, int y) override;
    void onMouseWheelScrolled(double scrollDelta) override;

};


#endif //CIVILIZATION_V_GAMESCREEN_H

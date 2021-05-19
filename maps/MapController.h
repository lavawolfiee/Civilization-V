#ifndef CIVILIZATION_V_MAPCONTROLLER_H
#define CIVILIZATION_V_MAPCONTROLLER_H

#include "Map.h"

class MapController: public Renderable {

private:
    std::shared_ptr<Map> map;
    std::shared_ptr<Unit> selectedUnit;

    void selectUnit(std::shared_ptr<Unit> unit);
    void deselectUnit();

    void moveUnit(std::shared_ptr<Unit> unit, int x, int y);

public:

    static std::pair< int, int > convertGlobalToMapCoord(int x, int y);

    void setMap(std::shared_ptr<Map> map);

    void onCellClicked(int x, int y);

    void render(std::shared_ptr<Batch> batch) override;

    std::shared_ptr<const Map> getMap() const;

    void addUnit(int x, int y, std::shared_ptr<Unit> unit);

};


#endif //CIVILIZATION_V_MAPCONTROLLER_H

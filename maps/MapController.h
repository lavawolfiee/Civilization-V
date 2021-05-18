#ifndef CIVILIZATION_V_MAPCONTROLLER_H
#define CIVILIZATION_V_MAPCONTROLLER_H

#include "Map.h"

class MapController: public Renderable {

private:
    std::shared_ptr<Map> map;
    std::shared_ptr<Unit> selectedUnit;

    void selectUnit(std::shared_ptr<Unit> unit);
    void deselectUnit();

public:

    static std::pair< int, int > convertGlobalToMapCoord(int x, int y);

    void setMap(std::shared_ptr<Map> map);

    void onCellClicked(int x, int y);

    void render(std::shared_ptr<Batch> batch) override;

    std::shared_ptr<const Map> getMap() const;

};


#endif //CIVILIZATION_V_MAPCONTROLLER_H

#ifndef CIVILIZATION_V_MAPGENERATOR_H
#define CIVILIZATION_V_MAPGENERATOR_H


#include "Map.h"

class MapGenerator {
public:
    virtual Map* generateMap() = 0;
};


#endif //CIVILIZATION_V_MAPGENERATOR_H

#ifndef CIVILIZATION_V_DUELMAPGENERATOR_H
#define CIVILIZATION_V_DUELMAPGENERATOR_H


#include "MapGenerator.h"
#include "DuelMap.h"

class DuelMapGenerator: public MapGenerator {
public:
    Map* generateMap() override;
};


#endif //CIVILIZATION_V_DUELMAPGENERATOR_H

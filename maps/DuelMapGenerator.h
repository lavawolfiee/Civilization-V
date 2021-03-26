#ifndef CIVILIZATION_V_DUELMAPGENERATOR_H
#define CIVILIZATION_V_DUELMAPGENERATOR_H


#include "MapGenerator.h"
#include "DuelMap.h"

class DuelMapGenerator: public MapGenerator {
public:
    std::shared_ptr<Map> generateMap() override;
};


#endif //CIVILIZATION_V_DUELMAPGENERATOR_H

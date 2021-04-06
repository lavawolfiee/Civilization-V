#ifndef CIVILIZATION_V_MAPGENERATOR_H
#define CIVILIZATION_V_MAPGENERATOR_H


#include "Map.h"

struct MapConfig {
    size_t width, height;
    MapConfig(size_t width, size_t height) : width(width), height(height) {};

    virtual ~MapConfig() = default;
};

class MapGenerator {
public:
    virtual std::shared_ptr<Map> generateMap() = 0;
    virtual std::shared_ptr<Map> generateMap(MapConfig& config) = 0;
};

#endif //CIVILIZATION_V_MAPGENERATOR_H

#ifndef CIVILIZATION_V_STANDARDMAPGENERATOR_H
#define CIVILIZATION_V_STANDARDMAPGENERATOR_H


#include "MapGenerator.h"

struct StandardMapConfig : MapConfig {
    std::vector<std::vector<Cell::Type> > types;
    std::vector<std::vector<double> > bounds;
    std::vector<double> frequency;
    std::vector<int> step;

    StandardMapConfig() : StandardMapConfig(56, 36, {{Cell::DEEPWATER, Cell::WATER, Cell::PLAIN}}, {{0.3, 0.4, 1.0}},
                                            {1.0}, {25}) {};

    StandardMapConfig(size_t width, size_t height, const std::vector<std::vector<Cell::Type> > &types,
                      const std::vector<std::vector<double> > &bounds, std::vector<double> frequency,
                      std::vector<int> step) : MapConfig(width, height), types(types), bounds(bounds),
                                               frequency(frequency), step(step) {};
};

class StandardMapGenerator : public MapGenerator {
public:
    std::shared_ptr<Map> generateMap() override;

    std::shared_ptr<Map> generateMap(MapConfig &config) override;
};


#endif //CIVILIZATION_V_STANDARDMAPGENERATOR_H

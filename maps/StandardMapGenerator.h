#ifndef CIVILIZATION_V_STANDARDMAPGENERATOR_H
#define CIVILIZATION_V_STANDARDMAPGENERATOR_H


#include "MapGenerator.h"

#include <utility>

struct StandardMapConfig : MapConfig {
    std::vector<std::vector<Cell::Type> > types;
    std::vector<std::vector<double> > bounds;
    std::vector<double> frequency;
    std::vector<int> step;

    StandardMapConfig() : StandardMapConfig(56, 36,
                                            {{Cell::DEEPWATER, Cell::WATER, Cell::PLAIN, Cell::HILL}},
                                            {{0.3, 0.4, 0.7, 1.0}},
                                            {1.0},
                                            {25}) {};

    StandardMapConfig(size_t width,
                      size_t height,
                      std::vector<std::vector<Cell::Type> > types,
                      std::vector<std::vector<double> > bounds,
                      std::vector<double> frequency,
                      std::vector<int> step) : MapConfig(width, height),
                                               types(std::move(types)),
                                               bounds(std::move(bounds)),
                                               frequency(std::move(frequency)),
                                               step(std::move(step)) {};
};

class StandardMapGenerator : public MapGenerator {
public:
    std::shared_ptr<Map> generateMap() override;

    std::shared_ptr<Map> generateMap(MapConfig& config) override;
};


#endif //CIVILIZATION_V_STANDARDMAPGENERATOR_H

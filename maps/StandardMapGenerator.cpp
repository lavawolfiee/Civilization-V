#include <noise/Noise.h>
#include "StandardMapGenerator.h"

std::shared_ptr<Map> StandardMapGenerator::generateMap(MapConfig &cfg) {
    StandardMapConfig config;
    try {
        config = dynamic_cast<StandardMapConfig &>(cfg);
    } catch (...) {
        return generateMap();
    }

    srand(time(nullptr));

    int width = config.width;
    int height = config.height;

    std::shared_ptr<Map> map = std::make_shared<Map>(width, height);

    for (int i = 0; i < config.types.size(); ++i) {
        Noise noise = Noise::noiseGenerator(anl::EFractalTypes::MULTI, anl::EBasisTypes::SIMPLEX,
                                            anl::EInterpTypes::QUINTIC, 6, config.frequency[i]);
        auto pixels = noise.generateNoise(width, height, config.step[i]);
        for(int y = 0; y < height; ++y) {
            for(int x = 0; x < width; ++x) {
                Cell::Type type;
                long long j = 0;
                for (; j < config.bounds[i].size() && pixels[y][x] > config.bounds[i][j]; ++j);
                type = config.types[i][j];
                map->setCell(x, y, std::make_shared<Cell>(type, x, y));
            }
        }
    }

    /*Noise surface = Noise::noiseGenerator(anl::EFractalTypes::MULTI, anl::EBasisTypes::SIMPLEX, anl::EInterpTypes::QUINTIC, 6, 1);
    Noise desert = Noise::noiseGenerator(anl::EFractalTypes::MULTI, anl::EBasisTypes::SIMPLEX, anl::EInterpTypes::QUINTIC, 6, 2);

    std::vector<Cell::Type> types = {Cell::DEEPWATER, Cell::WATER, Cell::PLAIN};
    std::vector<double> bounds = {0.3, 0.4, 1.0};

    std::vector< std::vector< double > > surfacePixels = surface.generateNoise(width, height, 25);
    std::vector< std::vector< double > > desertPixels = desert.generateNoise(width, height, 25);
    for(long long y = 0; y < height; ++y) {
        for(long long x = 0; x < width; ++x) {
            Cell::Type type;
            long long i = 0;
            for (; i < bounds.size() && surfacePixels[y][x] > bounds[i]; ++i);
            type = types[i];

            if(desertPixels[y][x] > 0.45 && type == Cell::PLAIN) type = Cell::DESERT;

            map->setCell(x, y, Cell(type));
        }
    }*/
    return map;
}

std::shared_ptr<Map> StandardMapGenerator::generateMap() {
    StandardMapConfig cfg;
    return generateMap(cfg);
}

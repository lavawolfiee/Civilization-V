#include "DuelMap.h"
#include "noise/Noise.h"

#include <iostream>

DuelMap::DuelMap() {
    srand(time(nullptr));

    int width = 56;
    int height = 36;
    field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::WATER));

    Noise surface = Noise::noiseGenerator(anl::EFractalTypes::MULTI, anl::EBasisTypes::SIMPLEX, anl::EInterpTypes::QUINTIC, 6, 1);
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

            field.at(y).at(x) = Cell(type);
        }
    }
}

bool DuelMap::generate_deposit(std::vector<std::vector<Cell>> &field, Cell::Type type, double probability,
                               double dist_coef) {
    int height = field.size();
    int width = field.at(0).size();
    auto f = [&](double x) {
        return 1 - 1 / (1 + 1 / (dist_coef * x * x));
    };

    std::queue<std::tuple<int, int, int>> queue;
    int rand_x = rand() % width;
    int rand_y = rand() % height;

    if (field.at(rand_y).at(rand_x).type == type)
        return false;
    if (type != Cell::PLAIN && field.at(rand_y).at(rand_x).type != Cell::PLAIN)
        return false;

    queue.push({rand_x, rand_y, 0});

    while (!queue.empty()) {
        int x, y, depth;
        std::tie(x, y, depth) = queue.front();
        queue.pop();

        if (field.at(y).at(x).type != type) {
            field.at(y).at(x) = Cell(type);
            std::vector<std::pair<int, int>> dirs = {{1,  0},
                                                     {-1, 0},
                                                     {0,  1},
                                                     {0,  -1},
                                                     {-1, 1},
                                                     {-1, -1}};

            if (y % 2 != 0)
                dirs = {{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1},
                        {1, 1},
                        {1, -1}};

            for (auto &dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && ny >= 0 && nx < width && ny < height && field.at(ny).at(nx).type != type) {
                    double p = probability * f(depth);

                    if (static_cast<double>(rand()) / RAND_MAX <= p) {
                        queue.push({nx, ny, depth + 1});
                    }
                }
            }
        }
    }

    return true;
}

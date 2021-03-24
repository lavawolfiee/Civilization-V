#include "DuelMap.h"

DuelMap::DuelMap() {
    srand(time(nullptr));

    int width = 42;
    int height = 27;
    field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::PLAIN));

    for (int i = 0; i < 4; ++i)
        generate_deposit(field, Cell::WATER, 0.65, 0.01);

    for (int i = 0; i < 3; ++i)
        generate_deposit(field, Cell::MOUNTAIN, 0.5, 0.1);

    for (int i = 0; i < 15; ++i)
        generate_deposit(field, Cell::HILL, 0.3, 0.5);

    for (int i = 0; i < 2; ++i)
        generate_deposit(field, Cell::DESERT, 0.6, 0.05);
}

void DuelMap::generate_deposit(std::vector<std::vector<Cell>> &field, Cell::Type type, double probability,
                               double dist_coef) {
    int height = field.size();
    int width = field.at(0).size();
    auto f = [&](double x) {
        return 1 - 1 / (1 + 1 / (dist_coef * x * x));
    };

    std::queue<std::tuple<int, int, int>> queue;
    queue.push({rand() % width, rand() % height, 0});

    while (!queue.empty()) {
        int x, y, depth;
        std::tie(x, y, depth) = queue.front();
        queue.pop();

        if (field.at(y).at(x).type != type) {
            field.at(y).at(x) = Cell(type);
            int dirs[4][2] = {{1,  0},
                              {0,  1},
                              {-1, 0},
                              {0,  -1}};

            for (auto & dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < width && ny < height && field.at(ny).at(nx).type != type) {
                    double p = probability * f(depth);

                    if (static_cast<double>(rand()) / RAND_MAX <= p) {
                        queue.push({nx, ny, depth + 1});
                    }
                }
            }
        }
    }
}

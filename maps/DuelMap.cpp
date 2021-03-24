#include "DuelMap.h"

DuelMap::DuelMap() {
    srand(time(nullptr));

    int width = 42;
    int height = 27;
    field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::WATER));

    for (int i = 0; i < 4;)
        if (generate_deposit(field, Cell::PLAIN, 0.55, 0.01))
            ++i;

    for (int i = 0; i < 3;)
        if (generate_deposit(field, Cell::MOUNTAIN, 0.2, 0.1))
            ++i;

    for (int i = 0; i < 15;)
        if (generate_deposit(field, Cell::HILL, 0.3, 0.75))
            ++i;

    for (int i = 0; i < 2;)
        if (generate_deposit(field, Cell::DESERT, 0.6, 0.1))
            ++i;
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

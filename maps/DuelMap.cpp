#include "DuelMap.h"

DuelMap::DuelMap() {
    srand(time(nullptr));

    int width = 42;
    int height = 27;
    field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::PLAIN));


}

void DuelMap::generate_deposit(const std::vector<std::vector<Cell>> &field, double probability) {
    int height = field.size();
    int width = field.at(0).size();

    std::set<std::tuple<int, int, int>> queue;
}

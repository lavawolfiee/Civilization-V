#include "Map.h"


Map::Map(size_t width, size_t height) : width(width),
                                        height(height),
                                        field(decltype(field)(height,
                                                              std::vector<std::shared_ptr<Cell> >(
                                                                      width,
                                                                      std::make_shared<Cell>(Cell::WATER)))),
                                        selected({-1, -1}) {}

void Map::setCell(size_t x, size_t y, std::shared_ptr<Cell> cell) {
    field.at(y).at(x) = std::move(cell);
}

void Map::selectCell(size_t x, size_t y) {
    selected = {x, y};
}

std::shared_ptr<const Cell> Map::getCell(size_t x, size_t y) const {
    return field.at(y).at(x);
}

std::shared_ptr<Cell> Map::getCell(size_t x, size_t y) {
    return field.at(y).at(x);
}

std::pair<size_t, size_t> Map::size() const {
    return std::make_pair(field.size(), field[0].size());
}

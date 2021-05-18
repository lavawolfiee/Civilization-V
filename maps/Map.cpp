#include "Map.h"


Map::Map(size_t width, size_t height) : width(width),
                                        height(height),
                                        field(std::vector<std::vector<Cell> >(height,
                                                                              std::vector<Cell>(
                                                                                      width,
                                                                                      Cell(Cell::WATER)))),
                                        selected({-1, -1}) {}

void Map::setCell(size_t x, size_t y, const Cell &cell) {
    field.at(y).at(x) = cell;
}

void Map::selectCell(size_t x, size_t y) {
    selected = {x, y};
}

const Cell &Map::getCell(size_t x, size_t y) const {
    return field.at(y).at(x);
}

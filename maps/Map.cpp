#include "Map.h"


Map::Map(size_t width, size_t height) : width(width),
                                        height(height),
                                        field(decltype(field)(height)) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            field.at(y).push_back(std::make_shared<Cell>(Cell::WATER, x, y));
        }
    }
}

void Map::setCell(size_t x, size_t y, std::shared_ptr<Cell> cell) {
    field.at(y).at(x) = std::move(cell);
}

std::shared_ptr<const Cell> Map::getCell(int x, int y) const {
    return field.at(y).at(x);
}

std::shared_ptr<Cell> Map::getCell(int x, int y) {
    return field.at(y).at(x);
}

std::pair<size_t, size_t> Map::size() const {
    return std::make_pair(field.size(), field[0].size());
}

std::shared_ptr<const Cell> Map::getCell(Point p) const {
    return getCell(p.x, p.y);
}

std::shared_ptr<Cell> Map::getCell(Point p) {
    return getCell(p.x, p.y);
}

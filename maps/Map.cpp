#include "Map.h"

void Map::render(std::shared_ptr<Batch> batch) {
    const double hexagonSize = 100;
    std::shared_ptr<Batch> cellBatch = std::make_shared<Batch>(*batch);
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            cellBatch->update(batch, j * (Cell::SIZE * sqrt(3) / 2.0) +
                                     (i % 2) * Cell::SIZE * sqrt(3) / 4.0,
                              i * Cell::SIZE * 3 / 4);
            field.at(i).at(j).render(cellBatch);
        }
    }
#ifdef debug
    cout << "[OK]. Drew map" << endl;
#endif
}

Map::Map(size_t width, size_t height) : width(width), height(height), field(std::vector<std::vector<Cell> >(height,
                                                                                                            std::vector<Cell>(
                                                                                                                    width,
                                                                                                                    Cell(Cell::WATER)))) {}

void Map::setCell(size_t x, size_t y, const Cell &cell) {
    field.at(y).at(x) = cell;
}

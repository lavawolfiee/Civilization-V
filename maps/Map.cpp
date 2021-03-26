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
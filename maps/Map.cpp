#include "Map.h"

void Map::render(Batch batch) {
    const double hexagonSize = 100;
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            field.at(i).at(j).render(Batch(&batch, j * (Cell::SIZE * sqrt(3) / 2.0) +
                                                                (i % 2) * Cell::SIZE * sqrt(3) / 4.0,
                                           i * Cell::SIZE * 3 / 4));
        }
    }
#ifdef debug
    cout << "[OK]. Drew map" << endl;
#endif
}

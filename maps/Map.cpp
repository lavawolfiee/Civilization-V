#include "Map.h"


//TODO: need to replace render of cells in cell.h
//TODO: Тёма е***ь пожалуйста ПЕРЕНЕСИ!!!
void Map::render(Batch batch) {
    const double hexagonSize = 100;
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            Color c;
            switch (field.at(i).at(j).type) {
                case Cell::WATER:
                    c = Color(13, 71, 161);
                    break;
                case Cell::PLAIN:
                    c = Color(139, 195, 74);
                    break;
                case Cell::HILL:
                    c = Color(56, 142, 60);
                    break;
                case Cell::MOUNTAIN:
                    c = Color(158, 158, 158);
                    break;
                case Cell::DESERT:
                    c = Color(255, 238, 88);
                    break;
            }
            batch.fillHexagon(j * (hexagonSize * sqrt(3) / 2.0) + (i % 2) * hexagonSize * sqrt(3) / 4.0,
                              i * hexagonSize * 3 / 4, hexagonSize / 2, c,
                              1, Color(0, 0, 0, 255));
        }
    }
#ifdef debug
    cout << "[OK]. Drew map" << endl;
#endif
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field.at(i).size(); ++j) {
            Cell& curCell = field[i][j];
            curCell.render(Batch(&batch, j * (hexagonSize * sqrt(3) / 2.0) + (i % 2) * hexagonSize * sqrt(3) / 4.0,
                                 i * hexagonSize * 3 / 4));
        }
    }
}

#include "Cell.h"

Cell::Cell(Cell::Type type): type(type) {

}

void Cell::setUnit(Unit *unit) {
    units.push_back(unit);
    unit->setCell(this);
}

void Cell::render(Batch batch) {
    Color c;
    switch (type) {
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

    batch.fillHexagon(0, 0, SIZE / 2, c,
                      1, Color(0, 0, 0, 255));
    for (Building* b : buildings)
        b->render(batch);

    for (Unit* u : units)
        u->render(batch);
}

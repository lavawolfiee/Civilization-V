#include "Cell.h"

Cell::Cell(Cell::Type type): type(type) {

}

void Cell::render(Batch batch) {
    for (Building* b : buildings)
        b->render(batch);

    for (Unit* u : units)
        u->render(batch);
}

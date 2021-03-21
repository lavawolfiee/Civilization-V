#include "Cell.h"

Cell::Cell(Cell::Type type): type(type) {

}

void Cell::render(GUI *gui) {
    for (Building* b : buildings)
        b->render(gui);

    for (Unit* u : units)
        u->render(gui);
}

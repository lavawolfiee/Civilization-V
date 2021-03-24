//TODO: Make different classes of ages units and add renders for them

#include "Unit.h"

void Unit::setCell(Cell* newCell) {
    currentCell = newCell;
}

void RangeUnit::render(Batch batch) {
    // batch.fillCircle(25, 25, 25, Color(200, 50, 200), 2);
#ifdef debug
    cout << "[OK]. Drew Range Unit" << endl;
#endif
}

void MeleeUnit::render(Batch batch) {

}

void CavalryUnit::render(Batch batch) {

}

void WorkerUnit::render(Batch batch) {

}

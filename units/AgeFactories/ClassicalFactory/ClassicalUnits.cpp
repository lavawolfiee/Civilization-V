#include "ClassicalUnits.h"
#include "../../../maps/Cell.h"

void ClassicalRangeUnit::render(Batch batch) {
    batch.fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(153, 50, 204), 2);
#ifdef debug
    cout << "[OK]. Drew Classical Range Unit" << endl;
#endif
}

void ClassicalMeleeUnit::render(Batch batch) {
    batch.fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(70, 130, 180), 2);
#ifdef debug
    cout << "[OK]. Drew Classical Melee Unit" << endl;
#endif
}

void ClassicalCavalryUnit::render(Batch batch) {
    batch.fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(160, 82, 45), 2);
#ifdef debug
    cout << "[OK]. Drew Classical Cavalry Unit" << endl;
#endif
}

void ClassicalWorkerUnit::render(Batch batch) {
    batch.fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(169, 169, 169), 2);
#ifdef debug
    cout << "[OK]. Drew Classical Worker Unit" << endl;
#endif
}

void ClassicalSettlerUnit::render(Batch batch) {
    batch.fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(250, 128, 114), 2);
#ifdef debug
    cout << "[OK]. Drew Classical Settler Unit" << endl;
#endif
}

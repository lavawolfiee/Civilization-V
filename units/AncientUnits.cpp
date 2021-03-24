#include "AncientUnits.h"
#include "../maps/Cell.h"

void AncientRangeUnit::render(Batch batch) {
    batch.fillCircle(Cell::SIZE / 4, Cell::SIZE / 4, Cell::SIZE / 4, Color(153, 50, 204), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Range Unit" << endl;
#endif
}

void AncientMeleeUnit::render(Batch batch) {
    batch.fillCircle(Cell::SIZE / 4, Cell::SIZE / 4, Cell::SIZE / 4, Color(70, 130, 180), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Melee Unit" << endl;
#endif
}

void AncientCavalryUnit::render(Batch batch) {
    batch.fillCircle(Cell::SIZE / 4, Cell::SIZE / 4, Cell::SIZE / 4, Color(160, 82, 45), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Cavalry Unit" << endl;
#endif
}

void AncientWorkerUnit::render(Batch batch) {
    batch.fillCircle(Cell::SIZE / 4, Cell::SIZE / 4, Cell::SIZE / 4, Color(169, 169, 169), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Worker Unit" << endl;
#endif
}

#include "AncientUnits.h"
#include "../../../maps/Cell.h"

void AncientRangeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) * 0.75, Color(153, 50, 204), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Range Unit" << endl;
#endif
}

void AncientMeleeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) * 0.75, Color(70, 130, 180), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Melee Unit" << endl;
#endif
}

void AncientCavalryUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) * 0.75, Color(160, 82, 45), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Cavalry Unit" << endl;
#endif
}

void AncientWorkerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) * 0.75, Color(169, 169, 169), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Worker Unit" << endl;
#endif
}

void AncientSettlerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) / 0.75, (Cell::SIZE / 4) * 0.75, Color(250, 128, 114), 2);
#ifdef debug
    cout << "[OK]. Drew Ancient Settler Unit" << endl;
#endif
}

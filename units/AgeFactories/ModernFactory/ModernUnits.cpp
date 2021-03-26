#include "ModernUnits.h"
#include "../../../maps/Cell.h"

void ModernRangeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) * 1.5, Color(153, 50, 204), 2);
#ifdef debug
    cout << "[OK]. Drew Modern Range Unit" << endl;
#endif
}

void ModernMeleeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) * 1.5, Color(70, 130, 180), 2);
#ifdef debug
    cout << "[OK]. Drew Modern Melee Unit" << endl;
#endif
}

void ModernCavalryUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) * 1.5, Color(160, 82, 45), 2);
#ifdef debug
    cout << "[OK]. Drew Modern Cavalry Unit" << endl;
#endif
}

void ModernWorkerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) * 1.5, Color(169, 169, 169), 2);
#ifdef debug
    cout << "[OK]. Drew Modern Worker Unit" << endl;
#endif
}

void ModernSettlerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) / 1.5, (Cell::SIZE / 4) * 1.5, Color(250, 128, 114), 2);
#ifdef debug
    cout << "[OK]. Drew Modern Settler Unit" << endl;
#endif
}

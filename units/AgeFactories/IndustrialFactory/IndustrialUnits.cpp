#include "IndustrialUnits.h"
#include "../../../maps/Cell.h"

void IndustrialRangeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(153, 50, 204), 2);
#ifdef debug
    cout << "[OK]. Drew Industrial Range Unit" << endl;
#endif
}

void IndustrialMeleeUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(70, 130, 180), 2);
#ifdef debug
    cout << "[OK]. Drew Industrial Melee Unit" << endl;
#endif
}

void IndustrialCavalryUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(160, 82, 45), 2);
#ifdef debug
    cout << "[OK]. Drew Industrial Cavalry Unit" << endl;
#endif
}

void IndustrialWorkerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(169, 169, 169), 2);
#ifdef debug
    cout << "[OK]. Drew Industrial Worker Unit" << endl;
#endif
}

void IndustrialSettlerUnit::render(std::shared_ptr<Batch> batch) {
    batch->fillCircle((Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) / 1.25, (Cell::SIZE / 4) * 1.25, Color(250, 128, 114), 2);
#ifdef debug
    cout << "[OK]. Drew Industrial Settler Unit" << endl;
#endif
}
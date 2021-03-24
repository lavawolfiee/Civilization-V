#include "Factory.h"

Unit* AncientUnitFactory::createUnit(UnitType unitType) const {
#ifdef debug
    cout << "[OK]. Doin Ancient Unit" << endl;
#endif
    switch (unitType) {
        case RANGE:
            return createRange();
        case MELEE:
            return createMelee();
        case CAVALRY:
            return createCavalry();
        case WORKER:
            return createWorker();
        case SETTLER:
            return createSettler();
        default:
#ifdef debug
    cout << "[FAILED]. Bad Unit type" << endl;
#endif
            exit(0);
    }
}

Unit* AncientUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Range" << endl;
#endif
    RangeUnit* currentUnit = new AncientRangeUnit(30, 5, 4, 3, 10);
#ifdef debug
    cout << "[OK]. Done new Ancient Range: 30hp, 3ar, 4mp, 10str" << endl;
#endif
    return currentUnit;
}

Unit* AncientUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Melee" << endl;
#endif
    MeleeUnit* currentUnit = new AncientMeleeUnit(50, 10, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Ancient Melee: 50hp, 1ar, 3mp, 10str" << endl;
#endif
    return currentUnit;
}

Unit* AncientUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Cavalry" << endl;
#endif
    CavalryUnit* currentUnit = new AncientCavalryUnit(40, 15, 7, 1);
#ifdef debug
    cout << "[OK]. Done new Ancient Cavalry: 40hp, 1ar, 7mp, 15str" << endl;
#endif
    return currentUnit;
}

Unit* AncientUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Ancient Worker. [OK]" << endl;
#endif
    WorkerUnit* currentUnit = new AncientWorkerUnit(3);
#ifdef debug
    cout << "Done new Ancient Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

Unit* AncientUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Ancient Settler. [OK]" << endl;
#endif
    SettlerUnit* currentUnit = new AncientSettlerUnit(3);
#ifdef debug
    cout << "Done new Ancient Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}
#include "Factory.h"

//TODO: Balance unit's stats. Can be doing in the late development stage

//----------=ANCIENT-FACTORY=----------
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

//END--------=ANCIENT-FACTORY=----------

//----------=CLASSICAL-FACTORY=----------
Unit* ClassicalUnitFactory::createUnit(UnitType unitType) const {
#ifdef debug
    cout << "[OK]. Doin Classical Unit" << endl;
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

Unit* ClassicalUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Classical Range" << endl;
#endif
    RangeUnit* currentUnit = new ClassicalRangeUnit(50, 10, 4, 3, 30);
#ifdef debug
    cout << "[OK]. Done new Classical Range: 50hp, 3ar, 4mp, 30str" << endl;
#endif
    return currentUnit;
}

Unit* ClassicalUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Classical Melee" << endl;
#endif
    MeleeUnit* currentUnit = new ClassicalMeleeUnit(80, 25, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Classical Melee: 80hp, 1ar, 3mp, 25str" << endl;
#endif
    return currentUnit;
}

Unit* ClassicalUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Classical Cavalry" << endl;
#endif
    CavalryUnit* currentUnit = new ClassicalCavalryUnit(60, 30, 8, 1);
#ifdef debug
    cout << "[OK]. Done new Classical Cavalry: 60hp, 1ar, 8mp, 30str" << endl;
#endif
    return currentUnit;
}

Unit* ClassicalUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Classical Worker. [OK]" << endl;
#endif
    WorkerUnit* currentUnit = new ClassicalWorkerUnit(3);
#ifdef debug
    cout << "Done new Classical Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

Unit* ClassicalUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Classical Settler. [OK]" << endl;
#endif
    SettlerUnit* currentUnit = new ClassicalSettlerUnit(3);
#ifdef debug
    cout << "Done new Classical Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

//END--------=CLASSICAL-FACTORY=----------

//----------=INDUSTRIAL-FACTORY=----------
Unit* IndustrialUnitFactory::createUnit(UnitType unitType) const {
#ifdef debug
    cout << "[OK]. Doin Industrial Unit" << endl;
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

Unit* IndustrialUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Range" << endl;
#endif
    RangeUnit* currentUnit = new IndustrialRangeUnit(70, 20, 4, 5, 50);
#ifdef debug
    cout << "[OK]. Done new Industrial Range: 70hp, 5ar, 4mp, 50str" << endl;
#endif
    return currentUnit;
}

Unit* IndustrialUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Melee" << endl;
#endif
    MeleeUnit* currentUnit = new IndustrialMeleeUnit(110, 45, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Industrial Melee: 110hp, 1ar, 3mp, 45str" << endl;
#endif
    return currentUnit;
}

Unit* IndustrialUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Cavalry" << endl;
#endif
    CavalryUnit* currentUnit = new IndustrialCavalryUnit(80, 70, 10, 1);
#ifdef debug
    cout << "[OK]. Done new Industrial Cavalry: 80hp, 1ar, 10mp, 70str" << endl;
#endif
    return currentUnit;
}

Unit* IndustrialUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Industrial Worker. [OK]" << endl;
#endif
    WorkerUnit* currentUnit = new IndustrialWorkerUnit(3);
#ifdef debug
    cout << "Done new Industrial Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

Unit* IndustrialUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Industrial Settler. [OK]" << endl;
#endif
    SettlerUnit* currentUnit = new IndustrialSettlerUnit(3);
#ifdef debug
    cout << "Done new Industrial Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

//END-------=INDUSTRIAL-FACTORY=----------

//------------=MODERN-FACTORY=------------
Unit* ModernUnitFactory::createUnit(UnitType unitType) const {
#ifdef debug
    cout << "[OK]. Doin Modern Unit" << endl;
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

Unit* ModernUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Modern Range" << endl;
#endif
    RangeUnit* currentUnit = new ModernRangeUnit(100, 35, 4, 6, 80);
#ifdef debug
    cout << "[OK]. Done new Modern Range: 100hp, 6ar, 4mp, 80str" << endl;
#endif
    return currentUnit;
}

Unit* ModernUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Modern Melee" << endl;
#endif
    MeleeUnit* currentUnit = new ModernMeleeUnit(150, 60, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Modern Melee: 150hp, 1ar, 3mp, 60str" << endl;
#endif
    return currentUnit;
}

Unit* ModernUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Modern Cavalry" << endl;
#endif
    CavalryUnit* currentUnit = new ModernCavalryUnit(110, 80, 12, 1);
#ifdef debug
    cout << "[OK]. Done new Modern Cavalry: 110hp, 1ar, 12mp, 80str" << endl;
#endif
    return currentUnit;
}

Unit* ModernUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Modern Worker. [OK]" << endl;
#endif
    WorkerUnit* currentUnit = new ModernWorkerUnit(3);
#ifdef debug
    cout << "Done new Modern Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

Unit* ModernUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Modern Settler. [OK]" << endl;
#endif
    SettlerUnit* currentUnit = new ModernSettlerUnit(3);
#ifdef debug
    cout << "Done new Modern Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}
//END---------=MODERN-FACTORY=--------
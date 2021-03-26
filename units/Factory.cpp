#include "Factory.h"

//TODO: Balance unit's stats. Can be doing in the late development stage

//----------=ANCIENT-FACTORY=----------
std::shared_ptr<Unit> AncientUnitFactory::createUnit(UnitType unitType) const {
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

std::shared_ptr<Unit> AncientUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Range" << endl;
#endif
    std::shared_ptr<RangeUnit> currentUnit = std::make_shared<AncientRangeUnit>(30, 5, 4, 3, 10);
#ifdef debug
    cout << "[OK]. Done new Ancient Range: 30hp, 3ar, 4mp, 10str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> AncientUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Melee" << endl;
#endif
    std::shared_ptr<MeleeUnit> currentUnit = std::make_shared<AncientMeleeUnit>(50, 10, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Ancient Melee: 50hp, 1ar, 3mp, 10str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> AncientUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Ancient Cavalry" << endl;
#endif
    std::shared_ptr<CavalryUnit> currentUnit = std::make_shared<AncientCavalryUnit>(40, 15, 7, 1);
#ifdef debug
    cout << "[OK]. Done new Ancient Cavalry: 40hp, 1ar, 7mp, 15str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> AncientUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Ancient Worker. [OK]" << endl;
#endif
    std::shared_ptr<WorkerUnit> currentUnit = std::make_shared<AncientWorkerUnit>(3);
#ifdef debug
    cout << "Done new Ancient Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> AncientUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Ancient Settler. [OK]" << endl;
#endif
    std::shared_ptr<SettlerUnit> currentUnit = std::make_shared<AncientSettlerUnit>(3);
#ifdef debug
    cout << "Done new Ancient Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

//END--------=ANCIENT-FACTORY=----------

//----------=CLASSICAL-FACTORY=----------
std::shared_ptr<Unit> ClassicalUnitFactory::createUnit(UnitType unitType) const {
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

std::shared_ptr<Unit> ClassicalUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Classical Range" << endl;
#endif
    std::shared_ptr<RangeUnit> currentUnit = std::make_shared<ClassicalRangeUnit>(50, 10, 4, 3, 30);
#ifdef debug
    cout << "[OK]. Done new Classical Range: 50hp, 3ar, 4mp, 30str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ClassicalUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Classical Melee" << endl;
#endif
    std::shared_ptr<MeleeUnit> currentUnit = std::make_shared<ClassicalMeleeUnit>(80, 25, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Classical Melee: 80hp, 1ar, 3mp, 25str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ClassicalUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Classical Cavalry" << endl;
#endif
    std::shared_ptr<CavalryUnit> currentUnit = std::make_shared<ClassicalCavalryUnit>(60, 30, 8, 1);
#ifdef debug
    cout << "[OK]. Done new Classical Cavalry: 60hp, 1ar, 8mp, 30str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ClassicalUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Classical Worker. [OK]" << endl;
#endif
    std::shared_ptr<WorkerUnit> currentUnit = std::make_shared<ClassicalWorkerUnit>(3);
#ifdef debug
    cout << "Done new Classical Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ClassicalUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Classical Settler. [OK]" << endl;
#endif
    std::shared_ptr<SettlerUnit> currentUnit = std::make_shared<ClassicalSettlerUnit>(3);
#ifdef debug
    cout << "Done new Classical Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

//END--------=CLASSICAL-FACTORY=----------

//----------=INDUSTRIAL-FACTORY=----------
std::shared_ptr<Unit> IndustrialUnitFactory::createUnit(UnitType unitType) const {
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

std::shared_ptr<Unit> IndustrialUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Range" << endl;
#endif
    std::shared_ptr<RangeUnit> currentUnit = std::make_shared<IndustrialRangeUnit>(70, 20, 4, 5, 50);
#ifdef debug
    cout << "[OK]. Done new Industrial Range: 70hp, 5ar, 4mp, 50str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> IndustrialUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Melee" << endl;
#endif
    std::shared_ptr<MeleeUnit> currentUnit = std::make_shared<IndustrialMeleeUnit>(110, 45, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Industrial Melee: 110hp, 1ar, 3mp, 45str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> IndustrialUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Industrial Cavalry" << endl;
#endif
    std::shared_ptr<CavalryUnit> currentUnit = std::make_shared<IndustrialCavalryUnit>(80, 70, 10, 1);
#ifdef debug
    cout << "[OK]. Done new Industrial Cavalry: 80hp, 1ar, 10mp, 70str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> IndustrialUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Industrial Worker. [OK]" << endl;
#endif
    std::shared_ptr<WorkerUnit> currentUnit = std::make_shared<IndustrialWorkerUnit>(3);
#ifdef debug
    cout << "Done new Industrial Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> IndustrialUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Industrial Settler. [OK]" << endl;
#endif
    std::shared_ptr<SettlerUnit> currentUnit = std::make_shared<IndustrialSettlerUnit>(3);
#ifdef debug
    cout << "Done new Industrial Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

//END-------=INDUSTRIAL-FACTORY=----------

//------------=MODERN-FACTORY=------------
std::shared_ptr<Unit> ModernUnitFactory::createUnit(UnitType unitType) const {
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

std::shared_ptr<Unit> ModernUnitFactory::createRange() const {
#ifdef debug
    cout << "[OK]. Doin Modern Range" << endl;
#endif
    std::shared_ptr<RangeUnit> currentUnit = std::make_shared<ModernRangeUnit>(100, 35, 4, 6, 80);
#ifdef debug
    cout << "[OK]. Done new Modern Range: 100hp, 6ar, 4mp, 80str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ModernUnitFactory::createMelee() const {
#ifdef debug
    cout << "[OK]. Doin Modern Melee" << endl;
#endif
    std::shared_ptr<MeleeUnit> currentUnit = std::make_shared<ModernMeleeUnit>(150, 60, 3, 1);
#ifdef debug
    cout << "[OK]. Done new Modern Melee: 150hp, 1ar, 3mp, 60str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ModernUnitFactory::createCavalry() const {
#ifdef debug
    cout << "[OK]. Doin Modern Cavalry" << endl;
#endif
    std::shared_ptr<CavalryUnit> currentUnit = std::make_shared<ModernCavalryUnit>(110, 80, 12, 1);
#ifdef debug
    cout << "[OK]. Done new Modern Cavalry: 110hp, 1ar, 12mp, 80str" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ModernUnitFactory::createWorker() const {
#ifdef debug
    cout << "Doin Modern Worker. [OK]" << endl;
#endif
    std::shared_ptr<WorkerUnit> currentUnit = std::make_shared<ModernWorkerUnit>(3);
#ifdef debug
    cout << "Done new Modern Worker: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}

std::shared_ptr<Unit> ModernUnitFactory::createSettler() const {
#ifdef debug
    cout << "Doin Modern Settler. [OK]" << endl;
#endif
    std::shared_ptr<SettlerUnit> currentUnit = std::make_shared<ModernSettlerUnit>(3);
#ifdef debug
    cout << "Done new Modern Settler: 3mp. [OK]" << endl;
#endif
    return currentUnit;
}
//END---------=MODERN-FACTORY=--------
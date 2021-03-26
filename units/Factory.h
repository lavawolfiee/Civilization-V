#ifndef CIVILIZATION_V_FACTORY_H
#define CIVILIZATION_V_FACTORY_H

#include "AgeFactories/AncientFactory/AncientUnits.h"
#include "AgeFactories/ClassicalFactory/ClassicalUnits.h"
#include "AgeFactories/IndustrialFactory/IndustrialUnits.h"
#include "AgeFactories/ModernFactory/ModernUnits.h"
#include "Unit.h"

class UnitFactory {
public:
    enum UnitType {
        RANGE,
        MELEE,
        CAVALRY,
        WORKER,
        SETTLER
    };
    virtual std::shared_ptr<Unit> createUnit(UnitType unitType) const = 0;
};

class AncientUnitFactory: public UnitFactory {
private:
    std::shared_ptr<Unit> createMelee() const;
    std::shared_ptr<Unit> createRange() const;
    std::shared_ptr<Unit> createCavalry() const;
    std::shared_ptr<Unit> createWorker() const;
    std::shared_ptr<Unit> createSettler() const;
public:

    std::shared_ptr<Unit> createUnit(UnitType unitType) const;
};

class ClassicalUnitFactory: public UnitFactory {
private:
    std::shared_ptr<Unit> createMelee() const;
    std::shared_ptr<Unit> createRange() const;
    std::shared_ptr<Unit> createCavalry() const;
    std::shared_ptr<Unit> createWorker() const;
    std::shared_ptr<Unit> createSettler() const;
public:

    std::shared_ptr<Unit> createUnit(UnitType unitType) const;
};

class IndustrialUnitFactory: public UnitFactory {
private:
    std::shared_ptr<Unit> createMelee() const;
    std::shared_ptr<Unit> createRange() const;
    std::shared_ptr<Unit> createCavalry() const;
    std::shared_ptr<Unit> createWorker() const;
    std::shared_ptr<Unit> createSettler() const;
public:

    std::shared_ptr<Unit> createUnit(UnitType unitType) const;
};

class ModernUnitFactory: public UnitFactory {
private:
    std::shared_ptr<Unit> createMelee() const;
    std::shared_ptr<Unit> createRange() const;
    std::shared_ptr<Unit> createCavalry() const;
    std::shared_ptr<Unit> createWorker() const;
    std::shared_ptr<Unit> createSettler() const;
public:

    std::shared_ptr<Unit> createUnit(UnitType unitType) const;
};

#endif //CIVILIZATION_V_FACTORY_H

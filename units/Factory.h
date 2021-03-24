#ifndef CIVILIZATION_V_FACTORY_H
#define CIVILIZATION_V_FACTORY_H

#include "AgeFactories/AncientFactory/AncientUnits.h"
#include "AgeFactories/ClassicalFactory/ClassicalUnits.h"
#include "AgeFactories/IndustrialFactory/IndustrialUnits.h"
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
    virtual Unit* createUnit(UnitType unitType) const = 0;
};

class AncientUnitFactory: public UnitFactory {
private:
    Unit* createMelee() const;
    Unit* createRange() const;
    Unit* createCavalry() const;
    Unit* createWorker() const;
    Unit* createSettler() const;
public:

    Unit* createUnit(UnitType unitType) const;
};

class ClassicalUnitFactory: public UnitFactory {
private:
    Unit* createMelee() const;
    Unit* createRange() const;
    Unit* createCavalry() const;
    Unit* createWorker() const;
    Unit* createSettler() const;
public:

    Unit* createUnit(UnitType unitType) const;
};

class IndustrialUnitFactory: public UnitFactory {
private:
    Unit* createMelee() const;
    Unit* createRange() const;
    Unit* createCavalry() const;
    Unit* createWorker() const;
    Unit* createSettler() const;
public:

    Unit* createUnit(UnitType unitType) const;
};

#endif //CIVILIZATION_V_FACTORY_H

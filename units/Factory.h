#ifndef CIVILIZATION_V_FACTORY_H
#define CIVILIZATION_V_FACTORY_H

#include "AncientUnits.h"

class UnitFactory {
public:
    enum UnitType {
        RANGE,
        MELEE,
        CAVALRY,
        WORKER
    };
    virtual Unit* createUnit(UnitType unitType) const = 0;
};

class AncientUnitFactory: public UnitFactory {
private:
    Unit* createMelee() const;
    Unit* createRange() const;
    Unit* createCavalry() const;
    Unit* createWorker() const;
public:

    Unit* createUnit(UnitType unitType) const;
};

#endif //CIVILIZATION_V_FACTORY_H

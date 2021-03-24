#ifndef CIVILIZATION_V_ANCIENTUNITS_H
#define CIVILIZATION_V_ANCIENTUNITS_H

#include "Unit.h"

class AncientRangeUnit: public RangeUnit {
public:
    AncientRangeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange, unsigned int strengthRange) :
            RangeUnit(maxHealth, strength, movePoints, attackRange, strengthRange)
    {};
    void render(Batch batch) override;
};

class AncientMeleeUnit: public MeleeUnit {
public:
    AncientMeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            MeleeUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(Batch batch) override;
};

class AncientCavalryUnit: public CavalryUnit {
public:
    AncientCavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            CavalryUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(Batch batch) override;
};

class AncientWorkerUnit: public WorkerUnit {
public:
    explicit AncientWorkerUnit(unsigned int movePoints) : WorkerUnit(movePoints) {};
    void render(Batch batch) override;
};

#endif //CIVILIZATION_V_ANCIENTUNITS_H

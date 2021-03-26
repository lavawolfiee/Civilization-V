#ifndef CIVILIZATION_V_INDUSTRIALUNITS_H
#define CIVILIZATION_V_INDUSTRIALUNITS_H

#include "../../Unit.h"

class IndustrialRangeUnit: public RangeUnit {
public:
    IndustrialRangeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange, unsigned int strengthRange) :
            RangeUnit(maxHealth, strength, movePoints, attackRange, strengthRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class IndustrialMeleeUnit: public MeleeUnit {
public:
    IndustrialMeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            MeleeUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class IndustrialCavalryUnit: public CavalryUnit {
public:
    IndustrialCavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            CavalryUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class IndustrialWorkerUnit: public WorkerUnit {
public:
    explicit IndustrialWorkerUnit(unsigned int movePoints) : WorkerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

class IndustrialSettlerUnit: public SettlerUnit {
public:
    explicit  IndustrialSettlerUnit(unsigned int movePoints) : SettlerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

#endif //CIVILIZATION_V_INDUSTRIALUNITS_H

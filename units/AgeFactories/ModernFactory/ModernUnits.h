#ifndef CIVILIZATION_V_MODERNUNITS_H
#define CIVILIZATION_V_MODERNUNITS_H

#include "../../Unit.h"

class ModernRangeUnit: public RangeUnit {
public:
    ModernRangeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange, unsigned int strengthRange) :
            RangeUnit(maxHealth, strength, movePoints, attackRange, strengthRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ModernMeleeUnit: public MeleeUnit {
public:
    ModernMeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            MeleeUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ModernCavalryUnit: public CavalryUnit {
public:
    ModernCavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            CavalryUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ModernWorkerUnit: public WorkerUnit {
public:
    explicit ModernWorkerUnit(unsigned int movePoints) : WorkerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ModernSettlerUnit: public SettlerUnit {
public:
    explicit  ModernSettlerUnit(unsigned int movePoints) : SettlerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

#endif //CIVILIZATION_V_MODERNUNITS_H

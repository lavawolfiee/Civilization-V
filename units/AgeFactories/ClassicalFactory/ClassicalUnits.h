#ifndef CIVILIZATION_V_CLASSICALUNITS_H
#define CIVILIZATION_V_CLASSICALUNITS_H

#include "../../Unit.h"

class ClassicalRangeUnit: public RangeUnit {
public:
    ClassicalRangeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange, unsigned int strengthRange) :
            RangeUnit(maxHealth, strength, movePoints, attackRange, strengthRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ClassicalMeleeUnit: public MeleeUnit {
public:
    ClassicalMeleeUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            MeleeUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ClassicalCavalryUnit: public CavalryUnit {
public:
    ClassicalCavalryUnit(int maxHealth, unsigned int strength, unsigned int movePoints, unsigned int attackRange) :
            CavalryUnit(maxHealth, strength, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ClassicalWorkerUnit: public WorkerUnit {
public:
    explicit ClassicalWorkerUnit(unsigned int movePoints) : WorkerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

class ClassicalSettlerUnit: public SettlerUnit {
public:
    explicit  ClassicalSettlerUnit(unsigned int movePoints) : SettlerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

#endif //CIVILIZATION_V_CLASSICALUNITS_H

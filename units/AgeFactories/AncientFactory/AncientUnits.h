#ifndef CIVILIZATION_V_ANCIENTUNITS_H
#define CIVILIZATION_V_ANCIENTUNITS_H

#include "../../Unit.h"

class AncientRangeUnit: public RangeUnit {
public:
    AncientRangeUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange, unsigned int damageRange) :
            RangeUnit(maxHealth, damage, movePoints, attackRange, damageRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class AncientMeleeUnit: public MeleeUnit {
public:
    AncientMeleeUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange) :
            MeleeUnit(maxHealth, damage, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class AncientCavalryUnit: public CavalryUnit {
public:
    AncientCavalryUnit(int maxHealth, unsigned int damage, unsigned int movePoints, unsigned int attackRange) :
            CavalryUnit(maxHealth, damage, movePoints, attackRange)
    {};
    void render(std::shared_ptr<Batch> batch) override;
};

class AncientWorkerUnit: public WorkerUnit {
public:
    explicit AncientWorkerUnit(unsigned int movePoints) : WorkerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

class AncientSettlerUnit: public SettlerUnit {
public:
    explicit  AncientSettlerUnit(unsigned int movePoints) : SettlerUnit(movePoints) {};
    void render(std::shared_ptr<Batch> batch) override;
};

#endif //CIVILIZATION_V_ANCIENTUNITS_H

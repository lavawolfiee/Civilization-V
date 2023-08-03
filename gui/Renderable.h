#ifndef CIVILIZATION_V_RENDERABLE_H
#define CIVILIZATION_V_RENDERABLE_H

#include "GUI.h"
#include "Batch.h"

class Renderable {
public:
    virtual void render(std::shared_ptr<Batch> batch) = 0;
};


#endif //CIVILIZATION_V_RENDERABLE_H

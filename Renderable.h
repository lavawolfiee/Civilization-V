#ifndef CIVILIZATION_V_RENDERABLE_H
#define CIVILIZATION_V_RENDERABLE_H

#include "GUI.h"

class Renderable {
public:
    virtual void render(GUI* gui) = 0;
};


#endif //CIVILIZATION_V_RENDERABLE_H

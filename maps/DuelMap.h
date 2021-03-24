#ifndef CIVILIZATION_V_DUELMAP_H
#define CIVILIZATION_V_DUELMAP_H


#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <tuple>

class DuelMap: public Map {
private:
    static void generate_deposit(std::vector<std::vector<Cell>>& field, Cell::Type type, double probability,
                                 double dist_coef);

public:
    DuelMap();
};


#endif //CIVILIZATION_V_DUELMAP_H

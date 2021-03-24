#ifndef CIVILIZATION_V_DUELMAP_H
#define CIVILIZATION_V_DUELMAP_H


#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <set>
#include <tuple>

class DuelMap: public Map {
private:
    static void generate_deposit(const std::vector<std::vector<Cell>>& field, double probability);

public:
    DuelMap();
};


#endif //CIVILIZATION_V_DUELMAP_H

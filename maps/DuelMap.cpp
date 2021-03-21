#include "DuelMap.h"

DuelMap::DuelMap() {
    field = {{Cell::WATER, Cell::WATER, Cell::PLAIN},
             {Cell::WATER, Cell::MOUNTAIN, Cell::DESERT},
             {Cell::PLAIN, Cell::HILL, Cell::MOUNTAIN}};
}

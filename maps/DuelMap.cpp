#include "DuelMap.h"

DuelMap::DuelMap() {
    field = {{Cell::WATER, Cell::WATER, Cell::PLAIN},
             {Cell::WATER, Cell::MOUNTAIN, Cell::DESERT},
             {Cell::PLAIN, Cell::HILL, Cell::MOUNTAIN}};
#ifdef debug
    cout << "[OK]. Want to add Ancient Range on 0, 2." << std::endl;
#endif
    Cell& curCell = field[0][2];
    AncientUnitFactory FstUnitFactory;
    curCell.setUnit(FstUnitFactory.createUnit(UnitFactory::UnitType::RANGE));
#ifdef debug
    cout << "[OK]. Added Ancient Range on 0, 2." << std::endl;
#endif
}

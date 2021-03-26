#include "DuelMapGenerator.h"

std::shared_ptr<Map> DuelMapGenerator::generateMap() {
    return std::make_shared<DuelMap>();
}
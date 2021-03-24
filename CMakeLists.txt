cmake_minimum_required(VERSION 3.17)
project(Civilization_V)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Ddebug")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Civilization_V main.cpp Game.cpp Game.h gui/GUI.h gui/SfmlGUI.cpp gui/SfmlGUI.h gui/Color.cpp gui/Color.h gui/GUI.cpp maps/Map.h maps/Cell.cpp maps/Cell.h gui/Renderable.h maps/DuelMap.cpp maps/DuelMap.h maps/Map.cpp maps/MapGenerator.h maps/DuelMapGenerator.cpp maps/DuelMapGenerator.h units/Unit.h buildings/Building.h gui/Batch.h gui/Batch.cpp gui/BatchGUI.cpp gui/BatchGUI.h units/Unit.cpp units/Factory.h units/Factory.cpp units/AgeFactories/AncientFactory/AncientUnits.h units/AgeFactories/AncientFactory/AncientUnits.cpp units/AgeFactories/ClassicalFactory/ClassicalUnits.h units/AgeFactories/ClassicalFactory/ClassicalUnits.cpp units/AgeFactories/IndustrialFactory/IndustrialUnits.cpp units/AgeFactories/IndustrialFactory/IndustrialUnits.h units/AgeFactories/ModernFactory/ModernUnits.cpp units/AgeFactories/ModernFactory/ModernUnits.h)

target_link_libraries(Civilization_V sfml-graphics sfml-audio)
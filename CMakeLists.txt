cmake_minimum_required(VERSION 3.17)
project(Civilization_V)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")# -Ddebug")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(TGUI 0.9 REQUIRED)
# find_library(libs/sfml-widgets libsfml-widgets)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(libs/accidentalnoise/include)
# include_directories(libs/sfml-widgets)

set(SOURCES main.cpp Game.cpp Game.h gui/GUI.h gui/SfmlGUI.cpp gui/SfmlGUI.h gui/Color.cpp gui/Color.h gui/GUI.cpp maps/Map.h maps/Cell.cpp maps/Cell.h gui/Renderable.h maps/DuelMap.cpp maps/DuelMap.h maps/Map.cpp maps/MapGenerator.h maps/StandardMapGenerator.cpp maps/StandardMapGenerator.h units/Unit.h buildings/Building.h gui/Batch.h gui/Batch.cpp gui/BatchGUI.cpp gui/BatchGUI.h units/Unit.cpp units/Factory.h units/Factory.cpp units/AgeFactories/AncientFactory/AncientUnits.h units/AgeFactories/AncientFactory/AncientUnits.cpp units/AgeFactories/ClassicalFactory/ClassicalUnits.h units/AgeFactories/ClassicalFactory/ClassicalUnits.cpp units/AgeFactories/IndustrialFactory/IndustrialUnits.cpp units/AgeFactories/IndustrialFactory/IndustrialUnits.h units/AgeFactories/ModernFactory/ModernUnits.cpp units/AgeFactories/ModernFactory/ModernUnits.h noise/Noise.cpp noise/Noise.h MapEditor.cpp MapEditor.h Player.cpp Player.h maps/MapController.cpp maps/MapController.h maps/MovementArea.cpp maps/MovementArea.h Utilities.cpp)

file(GLOB ANL_SOURCES libs/accidentalnoise/src/*.cpp)

add_executable(Civilization_V ${SOURCES} ${ANL_SOURCES})

target_link_libraries(Civilization_V sfml-graphics sfml-audio sfml-system tgui)# ${PROJECT_SOURCE_DIR}/libs/sfml-widgets/libsfml-widgets.a)
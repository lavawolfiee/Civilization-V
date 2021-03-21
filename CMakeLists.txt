cmake_minimum_required(VERSION 3.17)
project(Civilization_V)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Civilization_V main.cpp Game.cpp Game.h GUI.h SfmlGUI.cpp SfmlGUI.h Color.cpp Color.h GUI.cpp maps/Map.h Cell.cpp Cell.h Renderable.h maps/DuelMap.cpp maps/DuelMap.h maps/Map.cpp maps/MapGenerator.h maps/DuelMapGenerator.cpp maps/DuelMapGenerator.h units/Unit.h buildings/Building.h)

target_link_libraries(Civilization_V sfml-graphics sfml-audio)
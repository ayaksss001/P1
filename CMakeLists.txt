cmake_minimum_required(VERSION 3.14)
project(Game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs)

set(SOURCES
    src/main.c
    src/battle.c
    src/ui_map/ui.c
    src/game.c
    src/ui_map/map.c
    src/ui_map/menu.c
    src/entities/enemyManager.c
    src/entities/enemies.c
    src/ui_map/shop.c
    log/logger.cpp
    log/logger_c_bridge.cpp
)

add_executable(game ${SOURCES})

find_package(Curses REQUIRED)

target_link_libraries(game PRIVATE ${CURSES_LIBRARIES} tinfo)

target_include_directories(game PRIVATE 
    src
    src/entities       
    src/ui_map
    log
)

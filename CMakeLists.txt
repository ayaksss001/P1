cmake_minimum_required(VERSION 3.14)
project(Game)

add_subdirectory(libs)

set(SOURCES
    src/main.c
    src/battle.c
    src/ui.c
    src/game.c
    src/audio.c
    src/map.c

)

add_executable(game ${SOURCES})
find_package(Curses REQUIRED) 
find_library(PORTAUDIO_LIB portaudio REQUIRED)

target_link_libraries(game PRIVATE ${CURSES_LIBRARIES} ${PORTAUDIO_LIB})   

target_include_directories(game PRIVATE src portaudio)


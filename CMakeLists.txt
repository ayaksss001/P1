cmake_minimum_required(VERSION 3.14)
project(Game)

add_subdirectory(libs)

set(SOURCES
    src/main.c
    src/battle.c
    src/name.c
)

add_executable(game ${SOURCES})
find_package(Curses REQUIRED) 

target_link_libraries(game PRIVATE ${CURSES_LIBRARIES})   

target_include_directories(game PRIVATE src)


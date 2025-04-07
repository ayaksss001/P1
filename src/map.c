#include <stdlib.h>
#include <ncurses.h>
#include "map.h"

Map createMap(int height, int width)
{
    Map map;
    map.height = height;
    map.width = width;

    map.tiles = malloc(height * sizeof(char *));
    for(int i = 0 ; i < height ; i++)
    {
        map.tiles[i] = malloc(width * sizeof(char));
    }
    return map;
}

void freeMap(Map *map)
{
    for(int i = 0; i < map->height; i++)
    {
        free(map->tiles[i]);
    }
    free(map->tiles);
}

void drawBorder(Map *map)
{
    for(int y = 0 ; y <= map->height - 1; y++)
        {
            for(int x = 0 ; x <= map->width - 1; x++)
            {
                if(y == 0 || y == map->height - 1  ||x == 0 || x == map->width - 1)
                {
                map->tiles[y][x] = '*';
                mvaddch(y, x,'*');
                }
            }
        }
}


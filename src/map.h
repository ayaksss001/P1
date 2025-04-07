#ifndef MAP_H
#define MAP_H

typedef struct
{
    int height;
    int width;
    char **tiles;
}Map;

Map createMap(int height, int width);
void freeMap(Map *map);
void drawBorder(Map *map);

#endif 

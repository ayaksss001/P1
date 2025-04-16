#ifdef __cplusplus
extern "C" {
#endif
#include "logger.h"
#ifdef __cplusplus
}
#endif

#include <stdio.h>//printf(),getchar()
#include<stdlib.h>
#include <time.h>
#include<stdbool.h>
#include <ncurses.h>

#include "game.h"
#include "ui.h"
#include "entities.h"
#include "battle.h"
#include "map.h"
#include "enemyManager.h"
#include "menu.h"
#include "shop.h"

typedef enum{
    MENU,
    GAME,
    SHOP
}GameState;



void InitEnemies();

int dungeon(Map *map, Player* player)
{
    drawBorder(map);
    
    Enemy *goblin = GetEnemy(GOBLIN, COMMON);
    Enemy *dragon = GetEnemy(DRAGON, COMMON);

    for(int height = 0 ; height <= map->height - 1; height++)
        {
            for(int width = 0 ; width <= map->width - 1; width++)
            {
                if(map->tiles[height][width] != '#')
                {
                    map->tiles[height][width] = '*';
                    mvaddch(height, width,'*');
                }
            }
        }
            
        for(int height = 11 ; height <= map->height / 2; height++)
        {
            for(int width = 11 ; width <= map->width / 2 ; width++)
            {
                map->tiles[height][width] = ' ';
                mvaddch(height, width,' ');
            }
        }
    
        battle(player, goblin, map);
        battle(player, dragon, map);
        mvaddch(player->pos.y,player->pos.x, '@');
        draw_ui_window(0, 0, 5, 16);
        mvprintw(2,3,"Gold : %d", player->bank);
        draw_ui_window(0 ,map->width - 30, 6, 30);
        mvprintw(1,map->width - 28,"Hp : %d", goblin->currentHealth);
        mvprintw(2,map->width - 28,"Hp : %d", dragon->currentHealth);
}

void move_player(int c, Player *player, Map *map)
{
        log_info("Player pressed up");
        if(c == KEY_UP && map->tiles[player->pos.y - 1][player->pos.x] == ' ') player->pos.y--;
        else if(c == KEY_DOWN && map->tiles[player->pos.y + 1][player->pos.x] == ' ') player->pos.y++;
        else if(c == KEY_LEFT && map->tiles[player->pos.y][player->pos.x - 1] == ' ') player->pos.x--;
        else if(c == KEY_RIGHT && map->tiles[player->pos.y][player->pos.x + 1] == ' ') player->pos.x++;
}

int game(Player* player)   
{   
    clear();
    int max_height , max_width;
    getmaxyx(stdscr, max_height, max_width);
    srand(time(NULL));
    InitEnemies();
    
    int c;
    bool isTrue;
    
    srand(time(NULL));
    Map map = createMap(max_height, max_width);

    while(isTrue)
    {   
        if(c != 27)
        {
            dungeon(&map, player);  
            refresh();
            c = getch();
            flushinp();
            move_player(c, player, &map);
        }else 
        {
            isTrue = 0;
            refresh();
        }
    }
}
int gameLoop()
{
    Player player = 
    {
        .pos = {14, 14},
        .health = 3,
        .dmg = 1,
        .bank = 0,
        .skin = '@',
        .isAlive = true,
        .checkRespawn = false
        
    };

    initscr();
    cbreak();
    keypad(stdscr,1);//allow arrows
    noecho();//don't display input
    curs_set(0);//hide cursur
    

    GameState state = MENU;
    char input;
    bool mode = true;
    while(mode)
    {
        InitMenuWindow(&player);
        input = getch();
        if(input == '1') game(&player);
        else if (input == '2') InitShop(&player);
        else if(input == '3'|| input == 27) mode = false;

    }
    refresh();
    endwin();
}
#include <stdio.h>//printf(),getchar()
#include<stdlib.h>
#include <time.h>
#include<stdbool.h>
#include <ncurses.h>
#include "battle.h"

typedef struct{
    int y;
    int x;
    
}Position;






int dungeon(int max_height , int max_width, int c , Position *player, char (* map)[max_height])
{
    for(int height = 0 ; height <= max_height; height++)
        {
            for(int width = 0 ; width <= max_width ; width++)
            {
                map[height][width] = '#';
                mvaddch(height, width,'#');
            }
        }
            
        for(int height = 11 ; height <= max_height / 2; height++)
        {
            for(int width = 11 ; width <= max_width / 2 ; width++)
            {
                map[height][width] = ' ';
                mvaddch(height, width,' ');
            }
        }

        if(c == KEY_UP && map[player->y - 1][player->x] == ' ') player->y--;
        else if(c == KEY_DOWN && map[player->y + 1][player->x] == ' ') player->y++;
        else if(c == KEY_LEFT && map[player->y][player->x - 1] == ' ') player->x--;
        else if(c == KEY_RIGHT && map[player->y][player->x + 1] == ' ') player->x++;
}



int main(void)
{
    int max_height , max_width;
    Position player = {14 , 14};
    Position goblin = {20 , 17};
    int c;
    initscr();
    keypad(stdscr,1);//allow arrows
    noecho();//don't display input
    curs_set(0);//hide cursur
    
    getmaxyx(stdscr, max_height, max_width);
    char map[max_height] [max_width];
    
    do
    {
        dungeon(max_height, max_width, c , &player, map);

        
        //printw("height - %d, width - %d", max_height, max_width);
        mvaddch(goblin.y,goblin.x, 'o');
        mvaddch(player.y,player.x, '@');
        

    } while ((c = getch()) != 27);// 27 - ESC

    

    

    endwin();
    return 0;
}
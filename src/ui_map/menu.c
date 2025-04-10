#include "map.h"
#include "ui.h"
#include <ncurses.h>

void UiMenu(int max_height, int max_width)
{
    
    Map menu = createMap(max_height, max_width);
    for(int y = 0 ; y <= menu.height - 1 ; y++)
    {
        for(int x = 0 ; x <= menu.width - 1 ; x++)
        {
            menu.tiles[y][x] = '.';
            mvaddch(y, x, '.');
        }
    }
    draw_ui_window(menu.height / 2 - 10, menu.width / 2 - 15, 5, 30);
    draw_ui_window(menu.height / 2 - 5, menu.width / 2 - 15, 5, 30);
    draw_ui_window(menu.height / 2 , menu.width / 2 - 15, 5, 30);
    mvprintw(menu.height / 2 - 8, menu.width / 2 - 4 , "1.Go HUNT!");
    mvprintw(menu.height / 2 - 3, menu.width / 2 - 4 , "2.Shop");
    mvprintw(menu.height / 2 + 2, menu.width / 2 - 4 , "3.Exit");

    refresh();
    getch(); 
    flushinp();
    freeMap(&menu);
}

void InitMenuWindow()
{
    clear();

    int max_height, max_width;
    getmaxyx(stdscr, max_height, max_width);

    UiMenu(max_height, max_width);
    refresh();

    
    
}
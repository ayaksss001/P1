#include "map.h"
#include "ui.h"
#include "entities.h"
#include <ncurses.h>

#define ROWS 2
#define COLS 4

typedef struct {
    char name[16];
    int price;
    int y_offset;
    int x_offset;
    bool isEmpty;
} ShopItem;

ShopItem items[ROWS][COLS] = {
    {
        {" Sword ", 120, -12, -60, false},
        {" Bow ",   155, -12, -30, false},
        {"", 999, -12,   0, true},
        {"", 999, -12,  30, true}
    },
    {
        {"", 0,   4, -60, true},
        {"", 0,   4, -30, true},
        {"", 0,   4,   0, true},
        {"", 0,   4,  30, true}
    }
};

void UiShop(int max_height, int max_width, Player *player)
{
    
    Map shop = createMap(max_height, max_width);
    for(int y = 0 ; y <= shop.height - 1 ; y++)
    {
        for(int x = 0 ; x <= shop.width - 1 ; x++)
        {
            shop.tiles[y][x] = '.';
            mvaddch(y, x, '.');
        }
    }
    draw_ui_window(0, 0, 5, 16);
    mvprintw(2,3,"Gold : %d", player->bank);
    
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            
            int baseY = shop.height / 2 + items[i][j].y_offset;
            int baseX = shop.width / 2 + items[i][j].x_offset;
    
            draw_ui_window(baseY, baseX, 12, 24);
            if(!items[i][j].isEmpty)
            {
            mvprintw(baseY + 4, baseX + 8, "%s", items[i][j].name);
            mvprintw(baseY + 6, baseX + 8, "%d gold", items[i][j].price);
            }
            
            
        }
    }
    keypad(stdscr,1);
    int row = 0;
    int col = 0;
    int input;
    
    do
    {
        int baseY = shop.height / 2 + (items[row][col].y_offset + 9);
        int baseX = shop.width / 2 + (items[row][col].x_offset + 8);
    
        draw_ui_indicator(baseY, baseX, 8);
        
        int oldY = baseY;
        int oldX = baseX;

        input = getch();
        if(input == KEY_RIGHT && row <= 1 && col <= 6 )
        {   
            delete_ui_indicator(oldY, oldX, 8);
            col++;
            int baseY = shop.height / 2 + (items[row][col].y_offset + 9);
            int baseX = shop.width / 2 + (items[row][col].x_offset + 8);
    
            draw_ui_indicator(baseY, baseX, 8); 
        }
         else if(input == KEY_LEFT && row <= 1 && col > 0)
        {   
            delete_ui_indicator(oldY, oldX, 8);
            col--;
            int baseY = shop.height / 2 + (items[row][col].y_offset + 9);
            int baseX = shop.width / 2 + (items[row][col].x_offset + 8);

            draw_ui_indicator(baseY, baseX, 8); 
        }else if (input == 27)
        {
            break;
        }
        
    } while (input != 27);
    
    
    
    
    
    
    

    refresh();
    getch(); 
    flushinp();
    freeMap(&shop);
}

void InitShop(Player *player)
{
    clear();

    int max_height, max_width;
    getmaxyx(stdscr, max_height, max_width);

    UiShop(max_height, max_width, player);
    refresh();

    
    
}



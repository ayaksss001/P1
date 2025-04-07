#include <ncurses.h>

void draw_ui_window(int y, int x, int height, int width)
{
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width; j++)
        {
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                mvaddch(i + y, j + x, '#');
            }
            else
            {
                mvaddch(i + y, j + x, ' '); 
            }
        }
    }
    refresh();  
}

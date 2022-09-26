#include "curses.h"
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>

// Function Declarations
void paint_background();

void victory_splash(int game_over_state){
    // Takes the game over state and creates a victory splash
    char padding[] = "                                   ";
    char *str1 =     "              X Wins!              ";
    char *str2 =     "              O Wins!              ";
    char str3[] =    "         any key to continue...    ";
    char *str4 =     "             A tie game!           ";
    int len = strlen(padding);
    char *vic_pointer = NULL;
    // To avoid code duplication, use a pointer to pick the right string
    if(game_over_state == 1){
        vic_pointer = str1;
    }else if(game_over_state == 2){
        vic_pointer = str2;
    }else if(game_over_state == 3){
        vic_pointer = str4;
    }
    clear();
    paint_background();
    int row, col, x, y;
    getmaxyx(stdscr, row, col);
    y = row / 2 - 2;
    x = col / 2 - len / 2;
    mvprintw(y++, x, padding);
    mvprintw(y++, x, vic_pointer);
    mvprintw(y++, x, padding);
    mvprintw(y, x, str3);
    refresh();
    getch();
}

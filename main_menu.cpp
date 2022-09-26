#include "curses.h"
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>
// ctype.h for toupper(converting lowercase letters to uppercase)
#include <ctype.h>

// Function Declarations
void paint_background();

int main_menu(){
    clear();
    // Takes user input and returns an int that quits or starts a game
    int row, col, x, y;
    char error_string[] = " Invalid Input! Any key to try again... ";
    int error_str_len = strlen(error_string);
    char str1[] =      "        TIC TAC TOE       ";
    char padding[] =   "                          ";
    char str2[] =      "    (P)lay or (Q)uit?     ";
    int len = strlen(str1);
    paint_background();
    getmaxyx(stdscr, row, col);
    y = row / 2 - 2;
    x = col / 2 - len / 2;
    mvprintw(y++, x, padding);
    mvprintw(y++, x, str1);
    mvprintw(y++, x, padding);
    mvprintw(y++, x, str2);
    mvprintw(y++, x, padding);
    int input;
    refresh();
    // get user input and return it
    input = toupper(getch());
    if(input == 'P'){
        return 1;
    }else if(input == 'Q'){
        return 0;
    }else{
        // call the function again if the input is bad
        x = col / 2 - error_str_len / 2;
        mvprintw(++y, x, error_string);
        getch();
        main_menu();
    }
}

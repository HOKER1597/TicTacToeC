#include "curses.h"
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>
#include <stdlib.h>
// ctype.h for toupper(converting lowercase letters to uppercase)
#include <ctype.h>

// Function Declarations
void paint_background();

char pick_side(){
    // Takes user input and returns the chosen side
    clear();
    paint_background();
    int row, col, x, y;
    char str1[] =    " Press 'X' for X, 'O' for O, or 'R' for random! ";
    char str2[] =    "        Good choice! Any key to continue...     ";
    char padding[] = "                                                ";
    char err_str[] = "      Invalid input! Any key to continue...     ";
    int len = strlen(str1);
    getmaxyx(stdscr, row, col);
    y = row / 2 - 2;
    x = col / 2 - len / 2;
    mvprintw(y++, x, padding);
    mvprintw(y++, x, str1);
    mvprintw(y++, x, padding);
    int input;
    int pick;
    refresh();
    // Get user input for picking a side. 'R' is random.
    input = toupper(getch());
    if(input == 'X' || input == 'O'){
        mvprintw(y, x, str2);
        refresh();
        getch();
        return (char) input;
    }else if(input == 'R'){
        pick = rand() % 2;
        if(pick == 0){
            input = 'X';
        }else if(pick == 1){
            input = 'O';
        }
        mvprintw(y, x, str2);
        refresh();
        getch();
        return (char) input;
    }else{
        // Call the function again on bad input
        mvprintw(y, x, err_str);
        refresh();
        getch();
        pick_side();
    }
}

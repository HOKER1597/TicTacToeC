#include "curses.h"
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>
// #define's for the COLOR_PAIRs
#define X_COLOR 1
#define O_COLOR 2
#define BG_COLOR 3
// #defines used as a global constant
#define num_spaces 9

// Function Declarations
void paint_background();

void paint_board(char playable_spaces[num_spaces]){
    // paint the board and the playable spaces
    clear();
    paint_background();
    char break_lines[] = " ------- ";
    char play_lines[] =  " | | | | ";
    char padding[] =     "         ";
    int row, col, x, y;
    getmaxyx(stdscr, row, col);
    y = row / 2 - 4;
    int len;
    len = strlen(padding);
    x = col / 2 - len / 2;
    int k;
    const int num_lines = 9;
    attron(COLOR_PAIR(BG_COLOR));
    for(k = 0; k < num_lines; k++){
        // Paint the board itself without the pieces
        if(k == 0 || k == num_lines - 1){
            mvprintw(y + k, x, padding);
        }else{
            if(k % 2 == 0){
                mvprintw(y + k, x, play_lines);
            }else{
                mvprintw(y + k, x, break_lines);
            }
        }
    }
    attroff(COLOR_PAIR(BG_COLOR));
    // insert Xs and Os:
    // First set the dynamic x and y coordinates based on terminal size
    int playable_x[num_spaces] = {x+2, x+4, x+6, x+2, x+4, x+6, x+2, x+4, x+6};
    int playable_y[num_spaces] = {y+2, y+2, y+2, y+4, y+4, y+4, y+6, y+6, y+6};
    for(k = 0; k < num_spaces; k++){
        // For each of the playable spaces, first set the color
        if(playable_spaces[k] == 'O'){
            attron(COLOR_PAIR(O_COLOR));
        }else if(playable_spaces[k] == 'X'){
            attron(COLOR_PAIR(X_COLOR));
        }else{
            attron(COLOR_PAIR(BG_COLOR));
        }
        // then insert the char for that space into the proper spot on the terminal
        mvaddch(playable_y[k], playable_x[k], playable_spaces[k]);
    }
    // refresh the screen
    refresh();
}

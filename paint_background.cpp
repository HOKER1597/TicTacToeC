#include "curses.h"
#include <stdlib.h>
// #define's for the COLOR_PAIRs
#define X_COLOR 1
#define O_COLOR 2
#define BG_COLOR 3

void paint_background(){
    // Paints an elaborate flashy background
    int row, col, x, y;
    int pick;
    getmaxyx(stdscr, row, col);
    for(y = 0; y <= row; y++){
        for(x = 0; x <= col; x++){
            pick = rand() % 3;
            if(pick == 0){
                attron(COLOR_PAIR(X_COLOR));
                mvprintw(y, x, "X");
                attroff(COLOR_PAIR(X_COLOR));
            }else if(pick == 1){
                attron(COLOR_PAIR(O_COLOR));
                mvprintw(y, x, "O");
                attroff(COLOR_PAIR(O_COLOR));
            }else if(pick == 2){
                attron(COLOR_PAIR(BG_COLOR));
                mvprintw(y, x, " ");
                attroff(COLOR_PAIR(BG_COLOR));
            }
        }
    }
    refresh();
}

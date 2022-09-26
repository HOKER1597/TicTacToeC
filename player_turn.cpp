#include "curses.h"
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>
// ctype.h for toupper(converting lowercase letters to uppercase)
#include <ctype.h>
// #define's for the COLOR_PAIRs
#define X_COLOR 1
#define O_COLOR 2
#define BG_COLOR 3
// #defines used as a global constant
#define num_spaces 9

void player_turn(char *space_ptr, char playable_spaces[num_spaces], char side){
    // Function for the player turn
    char c;
  c = getch();
    char padding[] =  "                                                ";
    char str1[] =     "    Use arrow keys to move and 'P' to place!    ";
    char str2[] =     "                   Good move!                   ";
    char str3[] =     "                 Invalid input!                 ";
    char str4[] =     "             You can't move that way!           ";
    char str5[] =     "              Space already occupied!           ";
    int len = strlen(padding);
    int row, col, x, y;
    getmaxyx(stdscr, row, col);
    const int board_line_len = 9;
    const int board_lines = 9;
    y = row / 2 - board_line_len / 2;
    x = col / 2 - board_line_len / 2;
    // Use the same method of dynamically measuring where the spaces are at using
    // terminal size as in the paint_board() function.
    int playable_x[num_spaces] = {x+2, x+4, x+6, x+2, x+4, x+6, x+2, x+4, x+6};
    int playable_y[num_spaces] = {y+2, y+2, y+2, y+4, y+4, y+4, y+6, y+6, y+6};
    // The variables and mvprintw functions for the "info line"
    const int info_line_y = (row / 2 - board_lines / 2) + 10;
    const int info_line_x = col / 2 - len / 2;
    mvprintw(info_line_y - 1, info_line_x, padding);
    mvprintw(info_line_y, info_line_x, str1);
    mvprintw(info_line_y + 1, info_line_x, padding);
    // Using a loop and pointers to collect user input
    int moving = 1;
    int input;
    int *pos_x = &playable_x[0];
    int *pos_y = &playable_y[0];
    move(*pos_y, *pos_x);
    curs_set(1);
    refresh();
    while(moving){
        // For each movement key, if the move is valid, use pointer
        // arithmetic to mov pos_x and pos_y around.
        input = toupper(getch());
        if(input == KEY_UP){
            if(*pos_y != playable_y[0]){
                pos_y -= 3;
                move(*pos_y, *pos_x);
                refresh();
            }else{
                mvprintw(info_line_y, info_line_x, str4);
                move(*pos_y, *pos_x);
                refresh();
            }
        }else if(input == KEY_DOWN){
            if(*pos_y != playable_y[6]){
                pos_y += 3;
                move(*pos_y, *pos_x);
                refresh();
            }else{
                mvprintw(info_line_y, info_line_x, str4);
                move(*pos_y, *pos_x);
                refresh();
            }
        }else if(input == KEY_LEFT){
            if(*pos_x != playable_x[0]){
                pos_x -= 1;
                move(*pos_y, *pos_x);
                refresh();
            }else{
                mvprintw(info_line_y, info_line_x, str4);
                move(*pos_y, *pos_x);
                refresh();
            }
        }else if(input == KEY_RIGHT){
            if(*pos_x != playable_x[2]){
                pos_x += 1;
                move(*pos_y, *pos_x);
                refresh();
            }else{
                mvprintw(info_line_y, info_line_x, str4);
                move(*pos_y, *pos_x);
                refresh();
            }
        }else if(c == 32){
            // I wanted to use KEY_ENTER instead of 'P' but it would not work
            // for some reason. When the user presses 'P' it checks where the
            // cursor is and sets the space_ptr to the appropriate index in the
            // playable_spaces array.
            if(*pos_y == playable_y[0] && *pos_x == playable_x[0]){
                space_ptr = &playable_spaces[0];
            }else if(*pos_y == playable_y[1] && *pos_x == playable_x[1]){
                space_ptr = &playable_spaces[1];
            }else if(*pos_y == playable_y[2] && *pos_x == playable_x[2]){
                space_ptr = &playable_spaces[2];
            }else if(*pos_y == playable_y[3] && *pos_x == playable_x[3]){
                space_ptr = &playable_spaces[3];
            }else if(*pos_y == playable_y[4] && *pos_x == playable_x[4]){
                space_ptr = &playable_spaces[4];
            }else if(*pos_y == playable_y[5] && *pos_x == playable_x[5]){
                space_ptr = &playable_spaces[5];
            }else if(*pos_y == playable_y[6] && *pos_x == playable_x[6]){
                space_ptr = &playable_spaces[6];
            }else if(*pos_y == playable_y[7] && *pos_x == playable_x[7]){
                space_ptr = &playable_spaces[7];
            }else if(*pos_y == playable_y[8] && *pos_x == playable_x[8]){
                space_ptr = &playable_spaces[8];
            }
            // Then checks to see if that space is empty.
            // If so it sets the color properly and then places the piece.
            if(*space_ptr == ' '){
                if(side == 'X'){
                    attron(COLOR_PAIR(X_COLOR));
                    mvaddch(*pos_y, *pos_x, 'X');
                    attron(COLOR_PAIR(BG_COLOR));
                    *space_ptr = 'X';
                }else if(side == 'O'){
                    attron(COLOR_PAIR(O_COLOR));
                    mvaddch(*pos_y, *pos_x, 'O');
                    attron(COLOR_PAIR(BG_COLOR));
                    *space_ptr = 'O';
                }
                refresh();
                moving = 0;
            }else{
                mvprintw(info_line_y, info_line_x, str5);
                move(*pos_y, *pos_x);
                refresh();
            }
        }else{
            mvprintw(info_line_y, info_line_x, str3);
            move(*pos_y, *pos_x);
            refresh();
        }
    }
}

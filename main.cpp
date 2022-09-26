#include "curses.h"
// time for the random seed
#include <time.h>
// string.h for strlen(returns the length of the null-terminated string pointed to by str)
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// ctype.h for toupper(converting lowercase letters to uppercase)
#include <ctype.h>

// #define's for the COLOR_PAIRs
#define X_COLOR 1
#define O_COLOR 2
#define BG_COLOR 3
// #defines used as a global constant
#define num_spaces 9

// Function Declarations
void init_spaces(char *space_ptr);
void paint_board(char playable_spaces[num_spaces]);
void take_turn(char side, char *space_ptr, char playable_spaces[num_spaces]);
void victory_splash(int game_over_state);
void paint_background();
void player_turn(char *space_ptr, char playable_spaces[num_spaces], char side);
void ai_turn(char *space_ptr, char playable_spaces[num_spaces], char side);
void set_color_ai_side(char ai_side);
void set_color_side(char side);
int main_menu();
int evaluate_board(char playable_spaces[num_spaces]);
int spaces_left(char playable_spaces[num_spaces]);
int ai_fart(const int chance_to_fart);
int pick_random_space(char playable_spaces[num_spaces]);
int check_for_winning_move(char playable_spaces[num_spaces], char ai_side);
int check_for_block(char playable_spaces[num_spaces], char side);
int check_for_2_space_path(char playable_spaces[num_spaces], char ai_side);
char pick_side();

int main(){

    time_t t;
    srand((unsigned) time(&t));
    char playable_spaces[num_spaces] = {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
    char *space_ptr = &playable_spaces[0];

    // Game over
    char game_over_str[] =  " Game Over! Any key to continue... ";
    char go_padding[] = "                                   ";
    int game_over_len = strlen(game_over_str);
    int row, col, x, y;

    //curses init
    initscr();
    cbreak();
    keypad(stdscr, 1);
    curs_set(0);
    start_color();
    init_pair(X_COLOR, COLOR_CYAN, COLOR_BLACK);
    init_pair(O_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(BG_COLOR, COLOR_YELLOW, COLOR_BLACK);
    noecho();

    // Main Menu outer loop
    int running = 1;
    while(running){
        curs_set(0);
        // Main menu function quits or continues
        running = main_menu();
        // In-Game inner loop
        if(running == 0){
            break;
        }
        int playing = 1;
        while(playing){
            // Init all spaces to blank
            init_spaces(space_ptr);
            // Player picks their side
            char side = pick_side();
            // The inner, inner turn loop
            int turning = 1;
            while(turning){
                int game_over = 0;
                // Paint the board state as it is that turn
                paint_board(playable_spaces);
                // Function that governs the turn cycle
                take_turn(side, space_ptr, playable_spaces);
                // Evaluate the board for game over state
                game_over = evaluate_board(playable_spaces);
                if(game_over > 0){
                    // paint the board with a splash on game over
                    // so the player can evaluate the board for a moment
                    paint_board(playable_spaces);
                    getmaxyx(stdscr, row, col);
                    y = row / 2 + 6;
                    x = col / 2 - game_over_len / 2;
                    attron(COLOR_PAIR(BG_COLOR));
                    mvprintw(y++, x, go_padding);
                    mvprintw(y++, x, game_over_str);
                    mvprintw(y, x, go_padding);
                    refresh();
                    getch();
                    // call victory_splash with int game_over as a parameter
                    // 1 = X wins, 2 = O wins, 3 = Tie
                    victory_splash(game_over);
                    // Reset the turning and playing loops to effectively start over
                    turning = 0;
                    playing = 0;
                }
            }
        }
    }

    // end curses
    endwin();

    return 0;
}

#include "curses.h"
// #define's for the COLOR_PAIRs
#define X_COLOR 1
#define O_COLOR 2
#define BG_COLOR 3
// #defines used as a global constant
#define num_spaces 9

int ai_fart(const int chance_to_fart);
int pick_random_space(char playable_spaces[num_spaces]);
int check_for_winning_move(char playable_spaces[num_spaces], char ai_side);
int check_for_block(char playable_spaces[num_spaces], char side);

void ai_turn(char *space_ptr, char playable_spaces[num_spaces], char side){
    // wrapper for the AI turn
    /*
        Note: Since it is easy to accidentally create an unbeatable AI for tic tac toe
              I am building into the AI the chance for it to not make the optimal move.
                    This intentional fuzziness will be built into the functions that check for
                    avaialable spaces. When they find an optimal move they may just decide
                    to return 0 anyway.

        P-Code:
        if center square not taken, take center square 70% of the time;
        else:
            if opponent about to win, block them 90% of the time;
            elif self about to win take winning spot 90% of the time;
            else pick a random open spot;
    */
    // The chances for the AI to blow a move
    const int chance_to_fart_big_move = 10;
    const int chance_to_fart_center = 30;
    // Picking the character for the AI to use in its calculations
    char ai_side;
    if(side == 'X'){
        ai_side = 'O';
    }else if(side == 'O'){
        ai_side = 'X';
    }
    // Check the board state with a few functions.
    // These all return 0 if FALSE and the number of a valid
    // index to move into if TRUE
    int can_block_opponent = check_for_block(playable_spaces, side);
    int can_winning_move = check_for_winning_move(playable_spaces, ai_side);
    // Flow through the decision making logic applying the functions and checking for a fart
    int thinking = 1;
    int picked_space;
    while(thinking){
        if(playable_spaces[4] == ' '){
            if(!(ai_fart(chance_to_fart_center))){
                picked_space = 4;
                thinking = 0;
                break;
            }
        }
        if(can_winning_move){
            if(!(ai_fart(chance_to_fart_big_move))){
                picked_space = can_winning_move;
                thinking = 0;
            }else{
                picked_space = pick_random_space(playable_spaces);
                thinking = 0;
            }
        }else if(can_block_opponent){
            if(!(ai_fart(chance_to_fart_big_move))){
                picked_space = can_block_opponent;
                thinking = 0;
            }else{
                picked_space = pick_random_space(playable_spaces);
                thinking = 0;
            }
        }else{
            picked_space = pick_random_space(playable_spaces);
            thinking = 0;
        }
    }
    space_ptr = &playable_spaces[picked_space];
    if(ai_side == 'X'){
        attron(COLOR_PAIR(X_COLOR));
    }else if(ai_side == 'O'){
        attron(COLOR_PAIR(O_COLOR));
    }
    *space_ptr = ai_side;
    attron(COLOR_PAIR(BG_COLOR));
}

// #defines used as a global constant
#define num_spaces 9

// Function Declarations
void paint_board(char playable_spaces[num_spaces]);
void player_turn(char *space_ptr, char playable_spaces[num_spaces], char side);
void ai_turn(char *space_ptr, char playable_spaces[num_spaces], char side);
int evaluate_board(char playable_spaces[num_spaces]);
int spaces_left(char playable_spaces[num_spaces]);

void take_turn(char side, char *space_ptr, char playable_spaces[num_spaces]){
    // using "side" to determine the order, call the functions to play a whole turn
    if(side == 'X'){
        player_turn(space_ptr, playable_spaces, side);
        paint_board(playable_spaces);
        if(spaces_left(playable_spaces)){
            if(!(evaluate_board(playable_spaces))){
                ai_turn(space_ptr, playable_spaces, side);
                paint_board(playable_spaces);
            }
        }
    }else if(side == 'O'){
        ai_turn(space_ptr, playable_spaces, side);
        paint_board(playable_spaces);
        if(spaces_left(playable_spaces)){
            if(!(evaluate_board(playable_spaces))){
                player_turn(space_ptr, playable_spaces, side);
                paint_board(playable_spaces);
            }
        }
    }
}

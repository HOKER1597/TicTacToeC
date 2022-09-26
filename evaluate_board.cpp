// #defines used as a global constant
#define num_spaces 9

int evaluate_board(char playable_spaces[num_spaces]){
    // Evaluates the state of the playable spaces and either does nothing
    // or ends the game.
    // Check all the possible winning combinations:
    if(playable_spaces[0] == 'X' && playable_spaces[1] == 'X' && playable_spaces[2] == 'X'){
        return 1;
    }else if(playable_spaces[3] == 'X' && playable_spaces[4] == 'X' && playable_spaces[5] == 'X'){
        return 1;
    }else if(playable_spaces[6] == 'X' && playable_spaces[7] == 'X' && playable_spaces[8] == 'X'){
        return 1;
    }else if(playable_spaces[0] == 'X' && playable_spaces[3] == 'X' && playable_spaces[6] == 'X'){
        return 1;
    }else if(playable_spaces[1] == 'X' && playable_spaces[4] == 'X' && playable_spaces[7] == 'X'){
        return 1;
    }else if(playable_spaces[2] == 'X' && playable_spaces[5] == 'X' && playable_spaces[8] == 'X'){
        return 1;
    }else if(playable_spaces[0] == 'X' && playable_spaces[4] == 'X' && playable_spaces[8] == 'X'){
        return 1;
    }else if(playable_spaces[2] == 'X' && playable_spaces[4] == 'X' && playable_spaces[6] == 'X'){
        return 1;
    }else if(playable_spaces[0] == 'O' && playable_spaces[1] == 'O' && playable_spaces[2] == 'O'){
        return 2;
    }else if(playable_spaces[3] == 'O' && playable_spaces[4] == 'O' && playable_spaces[5] == 'O'){
        return 2;
    }else if(playable_spaces[6] == 'O' && playable_spaces[7] == 'O' && playable_spaces[8] == 'O'){
        return 2;
    }else if(playable_spaces[0] == 'O' && playable_spaces[3] == 'O' && playable_spaces[6] == 'O'){
        return 2;
    }else if(playable_spaces[1] == 'O' && playable_spaces[4] == 'O' && playable_spaces[7] == 'O'){
        return 2;
    }else if(playable_spaces[2] == 'O' && playable_spaces[5] == 'O' && playable_spaces[8] == 'O'){
        return 2;
    }else if(playable_spaces[0] == 'O' && playable_spaces[4] == 'O' && playable_spaces[8] == 'O'){
        return 2;
    }else if(playable_spaces[2] == 'O' && playable_spaces[4] == 'O' && playable_spaces[6] == 'O'){
        return 2;
    }else{
        // Check all spaces for a tie
        int hits = 0;
        int i;
        for(i = 0; i < num_spaces; i++){
            if(playable_spaces[i] != ' '){
                hits++;
            }
        }
        if(hits >= num_spaces){
            return 3;
        }else{
            return 0;
        }
    }
}

// #defines used as a global constant
#define num_spaces 9

int check_for_winning_move(char playable_spaces[num_spaces], char ai_side){
    // Checks to see if the AI can win the game with a final move and returns the
    // index of the valid move if TRUE, returns 0 if FALSE
    int space;
    int pick;
    int picked = 0;
    for(space = 0; space < num_spaces; space++){
        // For each space: Check to see if it is a potential winning space and if so
        // switch "picked" to 1 and set "pick" to the winning index
        switch(space){
            case(0):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == ai_side && playable_spaces[6] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == ai_side && playable_spaces[8] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(1):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[0] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == ai_side && playable_spaces[7] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(2):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == ai_side && playable_spaces[0] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == ai_side && playable_spaces[6] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[5] == ai_side && playable_spaces[8] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(3):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[4] == ai_side && playable_spaces[5] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[0] == ai_side && playable_spaces[6] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(4):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == ai_side && playable_spaces[7] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == ai_side && playable_spaces[5] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[0] == ai_side && playable_spaces[8] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[6] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(5):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[8] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == ai_side && playable_spaces[4] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(6):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[4] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[7] == ai_side && playable_spaces[8] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == ai_side && playable_spaces[0] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(7):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[6] == ai_side && playable_spaces[8] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == ai_side && playable_spaces[1] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(8):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[5] == ai_side && playable_spaces[2] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == ai_side && playable_spaces[0] == ai_side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[7] == ai_side && playable_spaces[6] == ai_side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
        }
    }
    // return winning index if any
    if(picked){
        return pick;
    }else{
        return 0;
    }
}

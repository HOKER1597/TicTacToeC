// #defines used as a global constant
#define num_spaces 9

int check_for_block(char playable_spaces[num_spaces], char side){
    // Checks to see if the AI can block the player from winning the game with a final move
    // and returns the index of the valid move if TRUE, returns 0 if FALSE
    // Note: I am sure there is a way to combine this this function with the
    //  check_for_winning_move() function in order to avoid code duplication, probably using
    //  one more parameter as a switch of some kind. I'd be open to examples of how to do that.
    int space;
    int pick;
    int picked = 0;
    for(space = 0; space < num_spaces; space++){
        // For each space: Check to see if it is a potential winning space and if so
        // switch "picked" to 1 and set "pick" to the winning index
        switch(space){
            case(0):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == side && playable_spaces[6] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == side && playable_spaces[8] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(1):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[0] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == side && playable_spaces[7] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(2):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == side && playable_spaces[0] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == side && playable_spaces[6] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[5] == side && playable_spaces[8] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(3):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[4] == side && playable_spaces[5] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[0] == side && playable_spaces[6] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(4):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[1] == side && playable_spaces[7] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == side && playable_spaces[5] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[0] == side && playable_spaces[8] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[6] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(5):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[8] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == side && playable_spaces[4] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(6):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[4] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[7] == side && playable_spaces[8] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[3] == side && playable_spaces[0] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(7):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[6] == side && playable_spaces[8] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == side && playable_spaces[1] == side){
                        pick = space;
                        picked = 1;
                    }
                }
                break;
            case(8):
                if(playable_spaces[space] == ' '){
                    if(playable_spaces[5] == side && playable_spaces[2] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[4] == side && playable_spaces[0] == side){
                        pick = space;
                        picked = 1;
                    }else if(playable_spaces[7] == side && playable_spaces[6] == side){
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

#include <stdlib.h>
// #defines used as a global constant
#define num_spaces 9

int pick_random_space(char playable_spaces[num_spaces]){
    // Returns a random open space on the board
    int roll;
    int rolling = 1;
    int pick;
    while(rolling){
        roll = rand() % num_spaces;
        if(playable_spaces[roll] == ' '){
            pick = roll;
            rolling = 0;
        }else{
            continue;
        }
    }
    return pick;
}

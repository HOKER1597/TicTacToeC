#include <stdlib.h>

int ai_fart(const int chance_to_fart){
    // Takes the fart chance and returns 1 if the AI blows the move, 0 otherwise
    int roll;
    roll = rand() % 100 + 1;
    if(roll < chance_to_fart){
        return 1;
    }else{
        return 0;
    }
}

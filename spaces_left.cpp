// #defines used as a global constant
#define num_spaces 9

int spaces_left(char playable_spaces[num_spaces]){
    // Returns 0 if no spaces left
    int hits = 0;
    int k;
    for(k = 0; k < num_spaces; k++){
        if(playable_spaces[k] == ' '){
        hits++;
        }
    }
    return hits;
}

void init_spaces(char *space_ptr){
    // init all the spaces to ' ';
    int i;
    for(i = 0; i < 9; i++){
        *space_ptr = ' ';
        space_ptr++;
    }
}

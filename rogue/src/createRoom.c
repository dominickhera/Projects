char ** createRoom(int roomY, int roomX){

char ** currentRoom;

currentRoom = malloc(sizeof(char*) *roomY);
    if(currentRoom == NULL){
        printf("failed to allocate memory for room\n");
        exit(1);
    }

    for(int i=0;i<roomY;i++){
        currentRoom[i] = malloc(sizeof(char*) *roomX);
        if(currentRoom[i] == NULL){
            printf("failed to allocate memory for \n");
            exit(1);
        }
    }
    //walls
    for(int i=0;i<roomX;i++){
        currentRoom[0][i] = '#';
    }

    for(int i=0;i<roomX;i++){
        currentRoom[roomY-1] [i] = '#';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[0][i] = '#';
    }

    for(int i=0;i<roomY;i++){
        currentRoom[roomX-1] [i] = '#';
    }

    //floor
    for(int i=1;i<roomY;i++){
        for(int k=1;k<roomX-1;k++){
            currentRoom[i][k] = '.';
        }
    }

    for(int i=0;i<roomY;i++){
        printf("%s\n", currentRoom[i]);
    }

    for(int i=0;i<roomY;i++){
        free(currentRoom[i]);
    }

    return currentRoom;
}

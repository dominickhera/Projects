room * parse() {    
FILE * openLevel;
room * roomThing;
roomThing = malloc(sizeof(room)); 

    if  (argc != 1) {
        printf("incorrect amount of arguments given\n");
        return 1;
    }

    openLevel = fopen(argv[1], "r");
   
   while(fgets(line, 256, openLevel) != NULL) {
        int counter = 0;
        length = strlen(line);
        line[length - 1] = '\0'
    }
/*
    roomThing->x = xInt;
    roomThing->y = yInt;
    roomThing->width = widthInt;
    roomThing-height = heighInt;
*/
    return roomThing;

}


for (int i = 0; i < length; i++) {
                while(line[i] != 'X') {
                    word[wordLength] = line[i];
                    wordLength++;
                    i++;
                }
            }
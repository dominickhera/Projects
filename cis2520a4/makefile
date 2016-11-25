CC = gcc
FILE = src/
OBJFILE = bin/
CFLAGS = -std=c99 -Wall -g
EXE = avltree 


all: $(EXE)

$(EXE): BIN avltree.o 
	$(CC) avltree.o -o ./bin/$(EXE)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

avltree.o: ./src/avltree.c
	$(CC) -c $(CFLAGS) $(FILE)avltree.c
		
clean:
	rm -rf ./BIN
	rm *.o

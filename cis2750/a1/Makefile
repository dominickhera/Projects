CC = gcc
FILE = src/
OBJFILE = bin/
CFLAGS = -std=c99 -Wall -g
EXE = a1 


all: $(EXE)

$(EXE): BIN a1.o 
	$(CC) a1.o -o ./bin/$(EXE)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

a1.o: ./src/a1.c
	$(CC) -c $(CFLAGS) $(FILE)a1.c
		
clean:
	rm -rf ./BIN
	rm *.o

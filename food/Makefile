FILES = src/main.o src/tracker.o  src/linkedList.o
CC = gcc
FILE = src/
INCLUDE = include
CFLAGS = -std=c99 -Wall -g -I$(INCLUDE)
EXE = tracker 


all: $(EXE)

$(EXE): OBJ BIN $(FILES)
	$(CC) $(FILE)main.o $(FILE)tracker.o $(FILE)linkedList.o -o ./bin/$(EXE)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

OBJ:
	if [ ! -d "obj" ]; then mkdir obj; fi
			
main.o: main.c
	$(CC) -c $(CFLAGS) $(FILE)main.c -I../include 
		
tracker.o: readFile.c
	$(CC) -c $(CFLAGS) $(FILE)tracker.c -I../include 

linkedList.o: linkedList.c
	$(CC) -c $(CFLAGS) $(FILE)linkedList.c -I../include 

clean:
	rm -rf ./OBJ
	rm -rf ./BIN

test:
	./bin/tracker ./assets/test.csv
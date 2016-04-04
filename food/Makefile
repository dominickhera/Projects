CFLAGS = -std=c99 -Wall
EXE = tracker

all: $(EXE)

$(EXE): main.o tracker.o BIN
	gcc -Wall -std=c99 -Iinclude main.o -o ./bin/$(EXE)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

test:
#compile something to test your list here

main.o: ./src/main.c
	gcc -c $(CFLAGS) ./src/main.c -Iinclude

tracker.o: ./src/tracker.c
	gcc -c $(CFLAGS) ./src/tracker.c -Iinclude

clean:
	rm *.o
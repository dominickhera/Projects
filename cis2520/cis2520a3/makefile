CFLAGS = -Wall
EXE1 = q1
EXE2 = q2

all: $(EXE1) $(EXE2)

$(EXE1): q1.o q1Functions.o BIN
	gcc q1.o q1Functions.o -o ./bin/$(EXE1)

$(EXE2): q2.o BIN
	gcc q2.o -o ./bin/$(EXE2)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

q1.o: ./src/q1.c
	gcc -c $(CFLAGS) ./src/q1.c -Iinclude

q2.o: ./src/q2.c
	gcc -c $(CFLAGS) ./src/q2.c -Iinclude

q1Functions.o: ./src/q1Functions.c
	gcc -c $(CFLAGS) ./src/q1Functions.c -Iinclude

clean:
	rm *.o
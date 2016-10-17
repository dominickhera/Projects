CFLAGS = -Wall
EXE1 = q1
EXE2 = q2

all: $(EXE1) $(EXE2)

$(EXE1): main.o BIN
	gcc main.o -o ./bin/$(EXE1)

$(EXE2): q2.o q2Stack.o BIN
	gcc q2.o q2Stack.o -o ./bin/$(EXE2)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

main.o: ./src/main.c
	gcc -c $(CFLAGS) ./src/main.c -Iinclude

avaliable.o: ./src/avaliable.c
	gcc -c $(CFLAGS) ./src/avaliable.c -Iinclude

q2.o: ./src/q2.c
	gcc -c $(CFLAGS) ./src/q2.c -Iinclude

q2Stack.o: ./src/q2Stack.c
	gcc -c $(CFLAGS) ./src/q2Stack.c -Iinclude

clean:
	rm *.o

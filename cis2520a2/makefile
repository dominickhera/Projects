CFLAGS = -Wall
EXE1 = q1
EXE2 = q2

all: $(EXE1) $(EXE2)

$(EXE1): main.o parse.o avaliable.o rented.o repair.o BIN
	gcc main.o parse.o avaliable.o rented.o repair.o -o ./bin/$(EXE1)

$(EXE2): q2.o q2Stack.o BIN
	gcc q2.o q2Stack.o -o ./bin/$(EXE2)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;


# run.o: ./src/run.c
# 	gcc -c $(CFLAGS) ./src/run.c -Iinclude

# functions.o: ./src/functions.c
# 	gcc -c $(CFLAGS) ./src/functions.c -Iinclude

# carbon.o: ./src/carbon.c
# 	gcc -c $(CFLAGS) ./src/carbon.c -Iinclude

# ackermann.o: ./src/ackermann.c
# 	gcc -c $(CFLAGS) ./src/ackermann.c -Iinclude

# newton.o: ./src/newton.c
# 	gcc -c $(CFLAGS) ./src/newton.c -Iinclude

clean:
	rm *.o

CC=gcc
CFLAGS= -Wall -std=c99 -lncurses
TARGET=run
FILES=./src/main.c ./src/parse.c ./src/draw.c
INCLUDE=./include


all: $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES) -I $(INCLUDE)

clean:
	rm $(TARGET)

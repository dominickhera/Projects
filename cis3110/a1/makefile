ll: msh
msh: my_shell.o lex.yy.o
	gcc -o msh my_shell.o lex.yy.o -lfl  
my_shell.o: ./src/my_shell.c
	gcc -Wall -g -c ./src/my_shell.c
lex.yy.o: ./src/lex.yy.c
	gcc -Wall -g -c ./src/lex.yy.c
lex.yy.c: ./src/lex.c
	flex ./src/lex.c
clean:
	rm -f lex.yy.c
	rm -f msh
	rm -f *.o

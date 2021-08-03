prog1: prog1.o my_io.o
	gcc -o prog1 prog1.o my_io.o

prog1.o: prog1.c my_io.h
	gcc -c prog1.c

my_io.o: my_io.c my_io.h
	gcc -c my_io.c

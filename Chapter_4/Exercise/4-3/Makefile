objects = main.o getch.o getop.o stack.o
calc : $(objects)
	gcc -g $(objects) -o calc 

main.o : main.c calc.h
	gcc -g -c main.c -o main.o

getch.o : getch.c calc.h
	gcc -g -c getch.c -o getch.o

getop.o : getop.c calc.h
	gcc -g -c getop.c -o getop.o

stack.o : stack.c calc.h
	gcc -g -c stack.c -o stack.o

clean : 
	rm calc $(objects)

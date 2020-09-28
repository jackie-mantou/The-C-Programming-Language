calc : main.o getch.o getop.o \
   stack.o 	
	#cc -o calc main.o getch.o getop.o \
		#stack.o
	gcc main.o getch.o getop.o stack.o -o calc 

main.o : main.c calc.h
	#cc -c main.c
	gcc -c main.c -o main.o

getch.o : getch.c calc.h
	#cc -c getch.c
	gcc -c getch.c -o getch.o

getop.o : getop.c calc.h
	#cc -c getop.c
	gcc -c getop.c -o getop.o

stack.o : stack.c calc.h
	#cc -c stack.c
	gcc -c stack.c -o stack.o

clean : 
	rm calc main.o getch.o getop.o \
		stack.o

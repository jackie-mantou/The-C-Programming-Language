objects = main.o getch.o getop.o stack.o
calc : $(objects)
	gcc -g $(objects) -o calc 

main.o : calc.h

getch.o : calc.h

getop.o : calc.h

stack.o : calc.h

clean : 
	rm calc $(objects)

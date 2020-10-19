main : 5-2.o getc.o
	gcc -g 5-2.o getc.o -o main

5-2.o : 5-2.c
	gcc -g -c 5-2.c -o 5-2.o

getc.o : getc.c
	gcc -g -c getc.c -o getc.o

clean :
	rm main 5-2.o getc.o

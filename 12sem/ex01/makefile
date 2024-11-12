all: main.o
	@gcc main.o -o main
	@clear
	@./main
	
main.o: main.c
	@gcc -c main.c -o main.o

clean:
	rm *.o main

debug: main.o
	@gcc main.o -o main -Wall
	@./main
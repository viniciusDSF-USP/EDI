L = lib/listas

all: main.o $(L).o
	@gcc main.o $(L).o -o main
	@./main

main.o: main.c $(L).h
	@gcc -c main.c -o main.o

$(L).o: $(L).c $(L).h
	@gcc -c $(L).c -o $(L).o

clean:
	@rm *.o lib/*.o main
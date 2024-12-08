M = lib/matriz

all: main.o $(M).o
	@gcc main.o $(M).o -o main
	@./main

main.o: main.c $(M).h
	@gcc -c main.c -o main.o

$(M).o: $(M).c $(M).h
	@gcc -c $(M).c -o $(M).o

clean:
	@rm *.o lib/*.o main
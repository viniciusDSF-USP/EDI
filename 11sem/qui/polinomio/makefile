pol = lib/polinomio

all: main.o $(pol).o
	@gcc main.o $(pol).o -o main -lm
	@./main

main.o: main.c $(pol).h
	gcc -c main.c -o main.o

$(pol).o: $(pol).c $(pol).h
	gcc -c $(pol).c -o $(pol).o

clean:
	rm -rf *.o lib/*.o main

run:
	clear
	./main
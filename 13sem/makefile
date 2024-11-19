A = lib/aluno

all: main.o $(A).o
	@gcc main.o $(A).o -o main -Wall
	@./main

main.o: main.c $(A).h
	@gcc -c main.c -o main.o
	
$(A).o: $(A).c $(A).h
	@gcc -c $(A).c -o $(A).o

clean:
	rm -rf *.o lib/*.o main
	
silent: main.o $(A).o
	@clear
	@gcc main.o $(A).o -o main -Wall
	@./main
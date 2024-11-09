mat = lib/matrizes

all: main.o $(mat).o
	@gcc main.o $(mat).o -o main
	@./main

main.o: main.c $(mat).h
	@gcc -c main.c -o main.o

$(mat).o: $(mat).c $(mat).h
	@gcc -c $(mat).c -o $(mat).o

clean:
	rm -rf *.o lib/*.o main
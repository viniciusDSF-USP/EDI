lis = lib/lista

all: main.o $(lis).o
	gcc main.o $(lis).o -o main
	./main

main.o: main.c $(lis).h
	gcc -c main.c -o main.o

$(lis).o: $(lis).c $(lis).h
	gcc -c $(lis).c -o $(lis).o

clean:
	rm -rf *.o lib/*.o main

run:
	clear
	./main
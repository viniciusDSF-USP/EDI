usu = lib/user
str = lib/str

all: main.o $(usu).o $(str).o
	gcc main.o $(usu).o $(str).o -o main
	./main

main.o: main.c $(usu).h
	gcc -c main.c -o main.o

$(usu).o: $(usu).c $(usu).h $(str).h
	gcc -c $(usu).c -o $(usu).o

$(str).o: $(str).c $(str).h
	gcc -c $(str).c -o $(str).o

clean:
	rm -rf *.o lib/*.o main

run:
	clear
	./main
big = lib/bignum

all: main.o $(big).o
	@gcc main.o $(big).o -o main
	@./main
	
main.o: main.c $(big).h
	gcc -c main.c -o main.o
	
$(big).o: $(big).c $(big).h
	gcc -c $(big).c -o $(big).o

clean:
	@rm -rf *.o lib/*.o main
#include <stdio.h>
#include <stdlib.h>
#include "lib/matrizes.h"

int main(){
	Matriz *M = criar(3,3);
	
	push(M, 1, 1, 3);
	push(M, 1, 3, 2);
	
	push(M, 2, 1, -1);
	
	push(M, 3, 3, 5);
	
	printf("M = \n");
	print(M);
	
	printf("\nM com zeros =\n");
	printZ(M);
	
	printf("\nSoma dos elementos de M: %d\n\n", soma(M));
	
	add(M, 0, 3, -2);
	printf("Adicionando -2 na coluna 3 de M:\n");
	print(M);
	
	printf("\nM com zeros =\n");
	printZ(M);

	return 0;
}
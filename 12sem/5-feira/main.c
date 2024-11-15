#include <stdio.h>
#include <stdlib.h>
#include "lib/avl.h"

int main(){
	AVL *A;
	
	A = criar();
	
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 20);
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 30);
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 10);
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 5);
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 6);
	print("A:\n", A, "\n-------\n\n");
	
	inserir(A, 15);
	print("A:\n", A, "\n");

	return 0;
}
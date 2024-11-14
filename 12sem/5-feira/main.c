#include <stdio.h>
#include <stdlib.h>
#include "lib/avl.h"

int main(){
	AVL *A;
	
	A = criar();
	
	print("A = [", A, "]\n\n");
	
	inserir(A, 20);
	print("A = [", A, "]\n\n");
	
	inserir(A, 30);
	print("A = [", A, "]\n\n");
	
	inserir(A, 10);
	print("A = [", A, "]\n\n");
	
	inserir(A, 5);
	print("A = [", A, "]\n\n");
	
	inserir(A, 6);
	print("A = [", A, "]\n\n");
	
	inserir(A, 15);
	print("A = [\n", A, "]\n\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "lib/avl.h"

int main(){
	AVL *A = criar();
	
	inserir(&A->raiz, 20);
	print("A:\n", A->raiz, "-----\n");
	
	inserir(&A->raiz, 30);
	print("A:\n", A->raiz, "-----\n");
	
	inserir(&A->raiz, 10);
	print("A:\n", A->raiz, "-----\n");
	
	inserir(&A->raiz, 5);
	print("A:\n", A->raiz, "-----\n");
	
	inserir(&A->raiz, 6);
	print("A:\n", A->raiz, "-----\n");
	
	inserir(&A->raiz, 15);
	print("A:\n", A->raiz, "-----\n");
	
	return 0;
}
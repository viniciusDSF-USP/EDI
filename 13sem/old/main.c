#include <stdio.h>
#include <stdlib.h>
#include "lib/aluno.h"

int main(){
	Aluno *A = criar_Aluno();
	
	if (A == NULL){
		printf("Erro! Memoria insuficiente!\n");
		return -8;
	}
	
	inserir_aluno(&A->raiz, "Maria", 123);
	inserir_filme(&A->raiz, 123, "Rambo");
	inserir_filme(&A->raiz, 123, "Alien");
	inserir_filme(&A->raiz, 123, "Vingadores");
	
	inserir_aluno(&A->raiz, "Pedro", 201);
	inserir_filme(&A->raiz, 201, "Vingadores");
	inserir_filme(&A->raiz, 201, "Toy Story");
	
	inserir_aluno(&A->raiz, "Joao", 54);
	inserir_filme(&A->raiz, 54, "Geladeira Diabolica");
	inserir_filme(&A->raiz, 54, "Alien");
	
	inserir_aluno(&A->raiz, "Violeta", 70);
	
	print_arvore("A:\n", A->raiz, "---\n\n");
	
	print_aluno("===\n", &A->raiz, 123, "===\n");

	return 0;
}
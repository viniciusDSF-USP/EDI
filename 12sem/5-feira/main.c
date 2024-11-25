#include <stdio.h>
#include <stdlib.h>
#include "lib/avl.h"

int main(){
	AVL *A = criar();
	
	int c = 1;
	
	inserir(&A->raiz, 20);
	inserir(&A->raiz, 30);
	inserir(&A->raiz, 10);
	inserir(&A->raiz, 5);
	inserir(&A->raiz, 6);
	inserir(&A->raiz, 15);
	
	while (c){
		printf("[0] Sair.\n");
		printf("[1] Inserir.\n");
		printf("[2] Remover.\n");
		printf("[3] Imprimir.\n");
		printf("[4] Limpar.\n");
		
		printf("Escolha: ");
		scanf("%d", &c);
		
		int v;
		switch (c){
			case 0:
				printf("Saindo!\n");
				break;
			case 1:
				printf("Valor: ");
				scanf("%d", &v);
				printf("%s", inserir(&A->raiz, v) ? "Inserido com sucesso!\n" : "Falha ao inserir!\n");
				break;
			case 2:
				printf("Valor: ");
				scanf("%d", &v);
				printf("%s", remover(&A->raiz, v) ? "Removido com sucesso!\n" : "Falha ao remover!\n");
				break;
			case 3:
				print("A:\n", A->raiz, "-----\n");
				break;
			case 4:
				system("clear");
				break;
			default:
				printf("Opcao invalida!\n");
				break;
		}
		
		printf("\n");
	}
	
	return 0;
}
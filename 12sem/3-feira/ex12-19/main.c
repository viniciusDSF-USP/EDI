#include <stdio.h>
#include <stdlib.h>
#include "lib/abb.h"

int main(){
	int atual = 1;
	int choice;
	
	ABB *A1, *A2, *NA;
	A1 = criar(1);
	A2 = criar(1);
	NA = criar(0);
	
	int v;
	int aux;

	choice = 0;
	printf("| 0 | Sair                         |\n");
	printf("| 1 | Inserir                      |\n");
	printf("| 2 | Remover                      |\n");
	printf("| 3 | Mostrar arvore               |\n");
	printf("| 4 | Mostrar percurso             |\n");
	printf("| 5 | Estruturalmente similar      |\n");
	printf("| 6 | Trocar de arvore (atual: %d) |\n", atual);
	printf("| 7 | Altura da arvore             |\n");
	printf("| 8 | A arvore eh ABB              |\n");
	printf("Escolha: ");
	if (scanf("%d", &choice) != 1){
		while (getchar() != '\n');
	}
	printf("\n");
	
	system("clear");
	
	switch(choice){
		case 0:
			printf("Saindo...");
			
			break;
		
		case 1:
			printf("Inserir\n\n");
			printf("Valor: ");
			if (scanf("%d", &v) != 1){
				while (getchar() != '\n');
				printf("Valor invalido!");
			} else {
				switch(atual){
					case 1:
						aux = inserir(&A1->raiz, &v);
						
						break;
						
					case 2:
						aux = inserir(&A2->raiz, &v);
						
						break;
					
					case 3:
						aux = inserir(&NA->raiz, &v);
						
						break;
				}
				
				if (aux)
					printf("Inserido com sucesso!");
				else
					printf("Erro ao inserir!");
			}
			
			break;
		
		case 2:
			printf("Remover\n\n");
			printf("Valor: ");
			if (scanf("%d", &v) != 1){
				while (getchar() != '\n');
				printf("Valor invalido!");
				break;
			}
			
			switch(atual){
				case 1:
					aux = remover(&A1->raiz, &v);
					
					break;
					
				case 2:
					aux = remover(&A2->raiz, &v);
					
					break;
				
				case 3:
					aux = remover(&NA->raiz, &v);
					
					break;
			}
			
			if (aux)
				printf("Removido com sucesso!");
			else
				printf("Erro ao remover!");
			
			break;
		
		case 3:
			switch(atual){
				case 1:
					printf("ABB 1:\n");
					print_tree(A1->raiz);
					
					break;
					
				case 2:
					printf("ABB 2:\n");
					print_tree(A2->raiz);
					
					break;
				
				case 3:
					printf("Nao ABB:\n");
					print_tree(NA->raiz);
					
					break;
			}
			
			break;
		
		case 4:
			printf("| 0 | Pre-ordem    |\n");
			printf("| 1 | Em-ordem     |\n");
			printf("| 2 | Pos-ordem    |\n");
			printf("| 3 | Largura      |\n");
			printf("| 4 | Profundidade |\n");
			printf("Escolha o percurso: ");
			if (scanf("%d", &aux) != 1){
				while (getchar() != '\n');
				printf("Opcao invalida!");
				break;
			}
			
			switch(atual){
				case 1:
					printf("ABB 1:\n");
					switch(aux){
						case 0:
							print_pre(A1->raiz);
					
							break;
				
						case 1:
							print_em(A1->raiz);
					
							break;
				
						case 2:
							print_pos(A1->raiz);
					
							break;
				
						case 3:
							print_width(A1->raiz);
					
							break;
				
						case 4:
							print_depth(A1->raiz);
					
							break;
					}
					
					break;
					
				case 2:
					printf("ABB 2:\n");
					switch(aux){
						case 0:
							print_pre(A2->raiz);
					
							break;
				
						case 1:
							print_em(A2->raiz);
					
							break;
				
						case 2:
							print_pos(A2->raiz);
					
							break;
				
						case 3:
							print_width(A2->raiz);
					
							break;
				
						case 4:
							print_depth(A2->raiz);
					
							break;
					}
					
					break;
				
				case 3:
					printf("Nao ABB:\n");
					switch(aux){
						case 0:
							print_pre(NA->raiz);
					
							break;
				
						case 1:
							print_em(NA->raiz);
					
							break;
				
						case 2:
							print_pos(NA->raiz);
					
							break;
				
						case 3:
							print_width(NA->raiz);
					
							break;
				
						case 4:
							print_depth(NA->raiz);
					
							break;
					}
					
					break;
			}
			
			break;
		
		case 5:
			printf("ABB1 eh estruturalmente similar a ABB2: ");
			if (estrut_sim(A1->raiz, A2->raiz))
				printf("Sim.");
			else
				printf("Nao.");
			
			break;
		
		case 6:
			if (atual == 3)
				atual = 1;
			else
				satual++;
			
			break;
		
		case 7:
			switch(atual){
				case 1:
					printf("ABB 1:\n");
					altura(A1->raiz);
					
					break;
					
				case 2:
					printf("ABB 2:\n");
					altura(A2->raiz);
					
					break;
				
				case 3:
					printf("Nao ABB:\n");
					altura(NA->raiz);
					
					break;
			}
			
			break;
		
		case 8:
			switch(atual){
				case 1:
					printf("ABB 1 eh ABB: ");
					if (ehABB(A1->raiz))
						printf("Sim.");
					else
						printf("Nao.");
					
					break;
					
				case 2:
					printf("ABB 2 eh ABB: ");
					if (ehABB(A2->raiz))
						printf("Sim.");
					else
						printf("Nao.");
					
					break;
				
				case 3:
					printf("Nao ABB eh ABB: ");
					if (ehABB(NA->raiz))
						printf("Sim.");
					else
						printf("Nao.");
					
					break;
			}
			
			break;
	}
	
	printf("\n\n");
	
	return 0;
}
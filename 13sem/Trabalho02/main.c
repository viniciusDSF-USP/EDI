#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/aluno.h"

void menu00(){
	printf("\t    Amigos de Graduacao Indo ao Cinema\n");
	printf("\t==========================================\n");
	printf("\tCody Stefano Barham Setti ........  4856322\n");
	printf("\tLuis Henrique de Queiroz Veras ... 14592414\n");
	printf("\tRaphael Mendes Batista ........... 15497660\n");
	printf("\tVinicius de Sa Ferreira .......... 15491650\n\n");

	printf("+===+===================+\n");
	printf("| 0 |       Sair        |\n");
	printf("| 1 | Entrar no sistema |\n");
	printf("+===+===================+\n");
	printf("Escolha: ");
}

void menu01(){
	printf("+====+===============================+\n");
	printf("|  0 |             Sair              |\n");
	printf("|  1 |        Cadastrar aluno        |\n");
	printf("|  2 |   Remover cadastro de aluno   |\n");
	printf("|  3 |   Adicionar filme predileto   |\n");
	printf("|  4 |    Remover filme predileto    |\n");
	printf("|  5 |   Listar alunos cadastrados   |\n");
	printf("|  6 |         Buscar aluno          |\n");
	printf("|  7 |   Listar filmes cadastrados   |\n");
	printf("|  8 |         Buscar filme          |\n");
	printf("|  9 |    Indicar colega similar     |\n");
	printf("| 10 |   Indicar colega diferente    |\n");
	printf("| 11 |        Gerar arquivo          |\n");
	printf("| 12 |   Mostrar dados das arvores   |\n");
	printf("| 13 |   Listar filmes mais citados  |\n");
	printf("| 14 | Cadastrar a partir de arquivo |\n");
	printf("| 15 |    Finalizar todos os dados   |\n");
	printf("| 16 |         Limpar a tela         |\n");
	printf("+====+===============================+\n");
	printf("Escolha: ");
}

int main(){
    int choice;
    menu00();
    scanf("%d", &choice);
    printf("\n");
    
    switch(choice){
    	case 1:
    		system("clear");
    		
    		break;
    		
    	default:
    		printf("Saindo...\n");
    		return 0;
    		
    		break;
    }
    
    AVL *Alunos = CriarAVL();
    AVL *Filmes = CriarAVL();
    char *string = (char *) malloc(STRLIM * sizeof(char));
    elem x;
    No **p, **q;
    
    choice = 1;
    while(choice){
    	menu01();
    	scanf("%d", &choice);
    	printf("\n");
    	
    	if (choice > 0 && choice <= 16) system("clear");
    	
    	switch(choice){
    		case 0: // Sair
    			printf("Saindo...\n");
    			return 0;
    			
    			break;
    		
    		case 1: // Cadastrar aluno
    			printf("Cadastrar aluno\n\n");
    			printf("\tNome do Aluno: ");
    			
    			getchar();
    			fgets(string, STRLIM, stdin);
    			string[strcspn(string, "\n")] = 0;
    			
    			x.info.aluno.nome = string;
    			
    			printf("\tNumero USP: ");
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;
    			
    			if (inserir(&Alunos->raiz, &x)){
    				printf("Aluno cadastrado com sucesso!");
    			} else {
    				printf("Erro ao cadastrar o aluno!");
    			}
    			
    			break;
    		
    		case 2: // Remover cadastro de aluno
    			printf("Remover cadastro de aluno\n\n");
    			printf("\tNumero USP: ");
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;

				p = buscar(&Alunos->raiz, &x);
				
				if (p != NULL){
					limpar_filmes_fav(&(*p)->info.aluno.filmes_fav, &Filmes->raiz);
					
					if (remover(&Alunos->raiz, &x)){
						printf("Aluno removido com sucesso!");
					} else {
						printf("Erro ao remover o aluno!");
					}
				} else
					printf("Erro ao remover o aluno!");
    			
    			break;
    		
    		case 3: // Adicionar filme predileto
    			printf("Adicionar filme predileto\n\n");
    			printf("\tNumero USP: ");
    			
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;
    			
    			p = buscar(&Alunos->raiz, &x);
    			if (p != NULL){
    				printf("\tNome do filme: ");
    			
					getchar();
					fgets(string, STRLIM, stdin);
					string[strcspn(string, "\n")] = 0;
					
					x.info.filme.nome = string;
					
					x.tipo = Filme;

					int aux = inserir(&Filmes->raiz, &x);
					q = buscar(&Filmes->raiz, &x);
					
					if (q != NULL){
						if (!aux) (*q)->info.filme.frequencia--;

						if (inserir_filme_fav(&(*p)->info.aluno.filmes_fav, q))
    						printf("Filme adicionado com sucesso!");
    					else {
    						if (aux)
								remover(&Filmes->raiz, &x);
							
    						printf("Erro ao adicionar o filme!");
    					}
					} else {
						printf("Erro ao adicionar o filme!");
					}
    			
    				
    			} else
    				printf("Aluno nao encontrado!");
    			
    			break;
    		
    		case 4: // Remover filme predileto
    			printf("Remover filme predileto\n\n");
    			printf("\tNumero USP: ");
    			
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;
    			
    			p = buscar(&Alunos->raiz, &x);
    			if (p != NULL){
    				printf("\tNome do filme: ");
    			
					getchar();
					fgets(string, STRLIM, stdin);
					string[strcspn(string, "\n")] = 0;
					
					x.info.filme.nome = string;
					
					x.tipo = Filme;
    			
					q = buscar(&Filmes->raiz, &x);
					
					if (q != NULL){
						if (remover_filme_fav(&(*p)->info.aluno.filmes_fav, q)){
							if ((*q)->info.filme.frequencia == 0){
								if (remover(&Filmes->raiz, &x))
									printf("Filme removido com sucesso!");
								else
									printf("Erro ao remover o filme!");
							} else {
								printf("Filme removido com sucesso!");
							}
						} else
							printf("Erro ao remover o filme!");
					} else
						printf("Filme nao encontrado!");
    			} else
    				printf("Aluno nao encontrado!");
    		
    			break;
    		
    		case 5: // Listar alunos cadastrados
    			if (Alunos->raiz != NULL){
    				printf("Alunos cadastrados:\n");
	    			imprimirAVL(Alunos);
    			} else
    				printf("Nao ha alunos cadastrados.");
	    		
    			break;
    		
    		case 6: // Buscar aluno
    			printf("Buscar aluno\n\n");
    			printf("\tNumero USP: ");
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;
    			
    			p = buscar(&Alunos->raiz, &x);
    			if (p != NULL)
    				printf("\nAluno encontrado:\n\t%s - %d", (*p)->info.aluno.nome, (*p)->info.aluno.nroUSP);
    			else
    				printf("Aluno nao encontrado!");
    			
    			break;
    		
    		case 7: // Listar filmes cadastrados
    			if (Filmes->raiz == NULL)
    				printf("Nao ha filmes cadastrados.");
    			else {
	    			printf("Filmes cadastrados:\n");
	    			imprimirAVL(Filmes);
	    		}
	    		
    			break;
    		
    		case 8: // Buscar filme
    			printf("Buscar filme\n\n");
    			printf("\tNome do filme: ");
    			
    			getchar();
    			fgets(string, STRLIM, stdin);
    			string[strcspn(string, "\n")] = 0;
    			
    			x.info.filme.nome = string;
    			
    			x.tipo = Filme;
    			
    			p = buscar(&Filmes->raiz, &x);
    			if (p != NULL)
    				printf("Filme encontrado! Citado %d vezes.", (*p)->info.filme.frequencia);
    			else
    				printf("Filme nao encontrado!");
    		
    			break;
    		
    		case 9:
    			break;
    		
    		case 10:
    			break;
    		
    		case 11:
    			break;
    		
    		case 12:
    			break;
    		
    		case 13:
    			break;
    		
    		case 14:
    			break;
    		
    		case 15: // Finalizar todos os dados
    			FinalizarAVL(&Alunos->raiz);
    			FinalizarAVL(&Filmes->raiz);
    			
    			printf("Dados apagados com sucesso!");
    			
    			break;
    		
    		case 16:
    			break;
    		
    		default:
    			printf("Opcao Invalida!");
    			
    			break;
    		
    	}
    	
    	if (choice != 16) printf("\n\n");
    }
    
    return 0;
}
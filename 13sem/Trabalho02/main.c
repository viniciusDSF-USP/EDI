#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/aluno.h"

void menu00(){
	printf("Amigos de Graduacao Indo ao Cinema\n\n");
	printf("\t\tINFOS\n\n");

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
	printf("|  2 |   Adicionar filme predileto   |\n");
	printf("|  3 |    Remover filme predileto    |\n");
	printf("|  4 |   Listar alunos cadastrados   |\n");
	printf("|  5 |         Buscar aluno          |\n");
	printf("|  6 |   Listar filmes cadastrados   |\n");
	printf("|  7 |         Buscar filme          |\n");
	printf("|  8 |    Indicar colega similar     |\n");
	printf("|  9 |   Indicar colega diferente    |\n");
	printf("| 10 |        Gerar arquivo          |\n");
	printf("| 11 |   Mostrar dados das arvores   |\n");
	printf("| 12 |   Remover cadastro de aluno   |\n");
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
    
    switch(choice){
    	case 1:
    		break;
    		
    	default:
    		printf("Saindo...\n");
    		return 0;
    		break;
    }
    
    AVL *Alunos = CriarAVL();
    AVL *Filmes = CriarAVL();
    char[STRLIM] string;
    elem x;
    
    choice = 1;
    while(choice){
    	menu01();
    	scanf("%d", &choice);
    	printf("\n");
    	
    	switch(choice){
    		case 0:
    			printf("Saindo...");
    			return 0;
    			break;
    		
    		case 1:
    			printf("\tNome do Aluno: ");
    			scanf("%"STRLIM-1"[^\n]", string);
    			x.info.aluno.nome = &string;
    			
    			printf("\tNumero USP: ");
    			scanf("%d", &x.info.aluno.nroUSP);
    			
    			x.tipo = Aluno;
    			
    			inserir(&Alunos->raiz, &x); 
    			
    			break;
    		
    		case 2:
    			break;
    		
    		case 3:
    			break;
    		
    		case 4:
    			break;
    		
    		case 5:
    			break;
    		
    		case 6:
    			break;
    		
    		case 7:
    			break;
    		
    		case 8:
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
    		
    		case 15:
    			break;
    		
    		case 16:
    			break;
    		
    		default:
    			printf("Opcao Invalida!");
    			break;
    		
    	}
    }
    
    return 0;
}
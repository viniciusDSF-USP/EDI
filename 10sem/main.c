#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/user.h"

void menu01(); // Integrantes do trabalho
int menu02(); // Entrar/Sair do sistema
void menu03(); // Tela com as opcoes do sistema
void clear();
void read(char *);
char *makestr();

int main(){
	menu01();
	printf("================================\n");

	if ( menu02() ){
		UserList *Usuarios;
		int created=0;
		char c;

		clear();
		printf("Bem-vindo! Selecione uma das acoes abaixo.\n");

		do {
			menu03(); // Tela com as opcoes do sistema
			scanf(" %c", &c);
			getchar();

			if (c != '0' && c != '9' && !created){
				Usuarios = createUserList();
				created = 1;
			}

			char *str1, *str2, *str3;
			switch(c-'0'){
				case 0: // Sair
					printf("Saindo...");
					break;

				case 1: // Cadastrar usuario
					str1 = makestr();
					str2 = makestr();

					printf("\tInsira o nome do usuario: ");
					read(str1);
					printf("\tInsira o apelido do usuario: ");
					read(str2);

					addUser(Usuarios, str1, str2);

					printf("Usuario cadastrado com sucesso!");
					break;

				case 2: // Listar usuarios
					printUserList(Usuarios);
					break;

				case 3: // Pedir parceria
					str1 = makestr();
					str2 = makestr();

					printf("\tSeu apelido: ");
					read(str1);
					printf("\tApelido de quem quer ser parceiro: ");
					read(str2);

					requestPartnership(Usuarios, str1, str2);
					free(str2);
					break;

				case 4: // Lista de pedidos
					str1 = makestr();

					printf("\tSeu apelido: ");
					read(str1);

					printRequests(Usuarios, str1);
					free(str1);
					break;

				case 5: // Enviar mensagem
					str1 = makestr();
					str2 = makestr();
					str3 = makestr();

					printf("\tSeu apelido: ");
					read(str1);
					printf("\tApelido do parceiro que quer enviar mensagem: ");
					read(str2);
					printf("\tMensagem:\n\t");
					read(str3);

					sendMessage(Usuarios, str1, str2, str3);
					free(str1);
					free(str2);
					break;

				case 6: // Ver mensagens
					str1 = makestr();

					printf("\tSeu apelido: ");
					read(str1);

					printMessages(Usuarios, str1);
					free(str1);
					break;

				case 7: // Sugerir parcerias
					str1 = makestr();

					printf("\tSeu apelido: ");
					read(str1);

					suggestPartnerships(Usuarios, str1);
					free(str1);
					break;

				case 8: // Reinicializar
					restart(Usuarios);
					printf("Lista de usuarios reinicializada com sucesso!");
					break;

				case 9: //
					clear();
					break;

				default:
					printf("Opcao invalida!");
					break;
			}

			printf("\n\n");
		} while (c != '0');
	}

    return 0;
}

void read(char *str){
	fgets(str, 100, stdin); str[strcspn(str, "\n")] = '\0';
}

char *makestr(){
	char *str = (char *) malloc(100*sizeof(char));
	if (str == NULL){
		printf("Falta de memoria! Encerrando...\n\n");
		exit(0);
	}
	return str;
}

void menu01(){
	printf("Parceiros de Trabalho - Trabalho 01 - EDI\n");
	printf("Nome | NUSP\n");
	printf("Nome | NUSP\n");
	printf("Nome | NUSP\n");
	printf("Nome | NUSP\n\n");
}

int menu02(){
	char c;
	do {
		printf("[0] Sair\n");
		printf("[1] Opcoes\n");
		printf("Escolha: ");

		scanf(" %c", &c);
		getchar();

		switch(c-'0'){
			case 0:
				printf("Saindo...\n\n");
				return 0;

			case 1:
				return 1; // Mostra as opcoes do sistema

			default:
				printf("Opcao invalida!\n\n");
				break;
		}
	} while (c != '0' && c != '1');
}

void menu03(){
	printf("+-+--------------------+\n");
	printf("|0|  Sair              |\n");
	printf("|1|  Cadastrar usuario |\n");
	printf("|2|  Listar usuarios   |\n");
	printf("|3|  Pedir parceria    |\n");
	printf("|4|  Lista de pedidos  |\n");
	printf("|5|  Enviar mensagem   |\n");
	printf("|6|  Ver mensagens     |\n");
	printf("|7|  Sugerir parcerias |\n");
	printf("|8|  Reinicializar     |\n");
	printf("|9|  Limpar tela       |\n");
	printf("+-+--------------------+\n");
	printf("Escolha: ");
}

void clear(){
	#ifdef WINDOWS
		system("cls");
	#else
		system("clear");
	#endif
}
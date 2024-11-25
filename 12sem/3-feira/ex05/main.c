#include <stdio.h>
#include <stdlib.h>
#include "lib/listas.h"

int main(){
    ListaGen *L;
    ListaDup *D;
    elem x;

    L = ListaGen_criar();
    D = ListaDup_criar();

    int choice = -1;
    while (choice){
        printf("[0] Sair;\n");
        printf("[1] Inserir no final;\n");
        printf("[2] Inserir em profundidade;\n");
        printf("[3] Mostrar lista generalizada;\n");
        printf("[4] Converter para lista linear duplamente encadeada;\n");
        printf("[5] Mostrar lista linear duplamente encadeada;\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        if (choice > 0) system("clear");

        switch(choice){
            case 1:
                int T, T2;

                printf("Tipo:\n");
                printf("\t[0] Atomo;\n");
                printf("\t[1] Sub-lista;\n");
                printf("\tEscolha: ");
                scanf("%d", &T);
                printf("\n");

                switch(T){
                    case 0:
                        printf("Tipo do atomo:\n");
                        printf("\t[0] Real;\n");
                        printf("\t[1] Inteiro;\n");
                        printf("\t[2] Char;\n");
                        printf("\tEscolha: ");
                        scanf("%d", &T2);
                        printf("\n");

                        switch (T2){
                            case 0:
                                x.tipo = Real;
                                printf("Insira o valor do elemento: ");
                                scanf("%f", &x.info.atom.f);
                                break;
                            
                            case 1:
                                x.tipo = Int;
                                printf("Insira o valor do elemento: ");
                                scanf("%d", &x.info.atom.i);
                                break;
                            
                            case 2:
                                x.tipo = Char;
                                getchar();
                                printf("Insira o valor do elemento: ");
                                scanf(" %c", &x.info.atom.c);
                                break;
                            
                            default:
                                printf("Tipo invalido!");
                                T2 = -1;
                                break;
                        }

                        if (T2 == -1) break;

                        if (ListaGen_inserir(&L->ini, &x, 0))
                            printf("Inserido com sucesso!");
                        else
                            printf("Erro ao inserir!");
                        break;
                    
                    case 1:
                        x.tipo = Sub;

                        if (ListaGen_inserir(&L->ini, &x, 0))
                            printf("Inserido com sucesso!");
                        else
                            printf("Erro ao inserir!");
                        break;
                    
                    default:
                        printf("Tipo invalido!");
                        break;
                }
                break;
            
            case 2:
                printf("Tipo do atomo:\n");
                printf("\t[0] Real;\n");
                printf("\t[1] Inteiro;\n");
                printf("\t[2] Char;\n");
                printf("\tEscolha: ");
                scanf("%d", &T2);
                printf("\n");

                switch (T2){
                    case 0:
                        x.tipo = Real;
                        printf("Insira o valor do elemento: ");
                        scanf("%f", &x.info.atom.f);
                        break;
                    
                    case 1:
                        x.tipo = Int;
                        printf("Insira o valor do elemento: ");
                        scanf("%d", &x.info.atom.i);
                        break;
                    
                    case 2:
                        x.tipo = Char;
                        getchar();
                        printf("Insira o valor do elemento: ");
                        scanf(" %c", &x.info.atom.c);
                        break;
                    
                    default:
                        printf("Tipo invalido!");
                        T2 = -1;
                        break;
                }

                if (T2 == -1) break;

                if (ListaGen_inserir(&L->ini, &x, 1))
                    printf("Inserido com sucesso!");
                else
                    printf("Erro ao inserir!");
                break;
            
            case 3:
                ListaGen_print(L);
                break;
            
            case 4:
                Limpar(&D->ini->esq);

                if (Converter(&L->ini, &D->ini))
                    printf("Conversao concluida com sucesso!");
                else
                    printf("Erro na conversao!");
                break;
            
            case 5:
                ListaDup_print(D);
                break;
            
            default:
                printf("Saindo...");
                break;
        }

        printf("\n\n");
    }
    
    return 0;
}
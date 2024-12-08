#include <stdio.h>
#include <stdlib.h>
#include "lib/matriz.h"

int main(){
    Matriz *M;

    M = criar(4, 4);

    inserir(M, 1, 3, 5);
    inserir(M, 3, 2, 3);
    inserir(M, 3, 4, 4);
    inserir(M, 2, 4, 4);

    printf("M:\n");
    print(M);

    somar_coluna(M, 4, -4);
    printf("Somando -4 na coluna 4:\n");
    print(M);

    somar_coluna(M, 4, 4);
    printf("Somando +4 na coluna 4:\n");
    print(M);

    somar_linha(M, 3, -3);
    printf("Somando -3 na linha 3:\n");
    print(M);

    return 0;
}
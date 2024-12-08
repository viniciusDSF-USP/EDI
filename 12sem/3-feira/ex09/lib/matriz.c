#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz *criar(int lin, int col){
    Matriz *M = (Matriz *) malloc(sizeof(Matriz));

    if (M != NULL){
        No *new = (No *) malloc(sizeof(No));

        if (new != NULL){
            new->lin = 0;
            new->col = 0;
            new->proxlin = new->proxcol = new;

            M->head = new;
        } else {
            exit(0);
        }

        No *p = M->head;
        for (int i=1; i<=lin; i++){
            new = (No *) malloc(sizeof(No));

            if (new != NULL){
                new->lin = i;
                new->col = 0;
                new->proxlin = p->proxlin;
                new->proxcol = new;

                p->proxlin = new;
                p = new;
            } else {
                exit(0);
            }
        }

        p = M->head;
        for (int j=1; j<=col; j++){
            new = (No *) malloc(sizeof(No));

            if (new != NULL){
                new->lin = 0;
                new->col = j;
                new->proxcol = p->proxcol;
                new->proxlin = new;

                p->proxcol = new;
                p = new;
            } else {
                exit(0);
            }
        }

        M->lin = lin;
        M->col = col;
    }

    return M;
}

int inserir(Matriz *M, int lin, int col, elem x){
    No *i, *j;
    i = j = M->head;

    while (j->lin != lin) j = j->proxlin;
    while (j->proxcol->col > 0 && j->proxcol->col <= col) j = j->proxcol;

    while (i->col != col) i = i->proxcol;
    while (i->proxlin->lin > 0 && i->proxlin->lin <= lin) i = i->proxlin;

    if (j->col != col){
        No *new = (No *) malloc(sizeof(No));

        if (new != NULL){
            new->info = x;
            new->lin = lin;
            new->col = col;

            new->proxlin = i->proxlin;
            new->proxcol = j->proxcol;

            i->proxlin = new;
            j->proxcol = new;
        } else {
            return 0;
        }
    }

    return 1;
}

int remover(Matriz *M, int lin, int col) {
    No *i, *j;
    i = j = M->head;

    while (j->lin != lin) j = j->proxlin;
    while (j->proxcol->col > 0 && j->proxcol->col < col) j = j->proxcol;

    while (i->col != col) i = i->proxcol;
    while (i->proxlin->lin > 0 && i->proxlin->lin < lin) i = i->proxlin;

    if (j->proxcol->col == col){
        No *aux = j->proxcol;

        i->proxlin = aux->proxlin;
        j->proxcol = aux->proxcol;

        free(aux);
    } else {
        return 0;
    }

    return 1;
}

void print(Matriz *M){
    No *p = M->head;

    p = p->proxlin;

    for (int i=1; i<=M->lin; i++){
        p = p->proxcol;
        for (int j=1; j<=M->col; j++){
            if (j == p->col){
                printf("%3d", p->info);
                p = p->proxcol;
            } else {
                printf("%3d", 0);
            }

            if (j < M->col) printf(" ");
        }
        printf("\n");
        p = p->proxlin;
    }

    printf("\n");
}

int somar_linha(Matriz *M, int lin, elem x){
    int ret=1;
    No *p = M->head, *aux;

    while (p->lin < lin) p = p->proxlin;
    p = p->proxcol;

    for (int j=1; j <= M->col; j++){
        if (j == p->col){
            p->info += x;

            if (p->info == 0) {
                aux = p->proxcol;
                ret = remover(M, lin, j);
                p = aux;
            }
        } else {
            ret = inserir(M, lin, j, x);
        }

        if (!ret) return 0;
    }

    return 1;
}

int somar_coluna(Matriz *M, int col, elem x){
    int ret=1;
    No *p = M->head, *aux;

    while (p->col < col) p = p->proxcol;
    p = p->proxlin;

    for (int i=1; i <= M->lin; i++){
        if (i == p->lin){
            p->info += x;

            if (p->info == 0) {
                aux = p->proxlin;
                ret = remover(M, i, col);
                p = aux;
            }
        } else {
            ret = inserir(M, i, col, x);
        }

        if (!ret) return 0;
    }

    return 1;
}
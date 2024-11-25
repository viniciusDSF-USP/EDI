#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

ListaGen *ListaGen_criar(){
    ListaGen *L = (ListaGen *) malloc(sizeof(ListaGen));

    if (L != NULL){
        L->ini = NULL;
    }

    return L;
}

ListaDup *ListaDup_criar(){
    ListaDup *D = (ListaDup *) malloc(sizeof(ListaDup));

    if (D != NULL){
        NoDup *sent = (NoDup *) malloc(sizeof(NoDup));

        if (sent != NULL){
            sent->tipo = -1;
            sent->esq = sent;
            sent->dir = sent;

            D->ini = sent;
        } else {
            free(D);
            D = NULL;
        }
    }

    return D;
}

int ListaGen_inserir(NoGen **L, elem *x, char prof){
    if (*L == NULL){
        NoGen *new = (NoGen *) malloc(sizeof(NoGen));

        if (new != NULL){
            switch(x->tipo){
                case Real:
                    new->info.atom.f = x->info.atom.f;
                    break;
                
                case Int:
                    new->info.atom.i = x->info.atom.i;
                    break;
                
                case Char:
                    new->info.atom.c = x->info.atom.c;
                    break;
            }

            new->tipo = x->tipo;
            new->prox = NULL;

            *L = new;

            return 1;
        } else {
            return 0;
        }
    }

    if (prof && (*L)->tipo == Sub && (*L)->prox == NULL)
        return ListaGen_inserir(&(*L)->info.sub, x, prof);
    
    return ListaGen_inserir(&(*L)->prox, x, prof);
}

void LGP_aux(NoGen *p){
    if (p == NULL) {
        printf(")");
        return;
    }

    switch(p->tipo){
        case Real:
            printf("%.2f", p->info.atom.f);
            break;
        
        case Int:
            printf("%d", p->info.atom.i);
            break;
        
        case Char:
            printf("%c", p->info.atom.c);
            break;
    }

    if (p->tipo != Sub){
        if (p->prox != NULL) printf(", ");
    } else {
        printf("(");
        LGP_aux(p->info.sub);
        if (p->prox != NULL) printf(", ");
    }

    LGP_aux(p->prox);
}

void ListaGen_print(ListaGen *L){
    printf("(");

    LGP_aux(L->ini);
}

void Limpar(NoDup **D){
    if ((*D)->tipo == -1) {
        (*D)->esq = *D;
        (*D)->dir = *D;
        return;
    }

    printf("Limpei o %c\n", (*D)->info.c);
    NoDup *aux = *D;
    *D = (*D)->esq;
    (*D)->dir = aux->dir;
    free(aux);

    Limpar(D);
}

int Converter(NoGen **L, NoDup **D){
    if (*L == NULL){
        return 1;
    }

    if ((*L)->tipo == Sub){
        int S = Converter(&(*L)->info.sub, D);
        int P = Converter(&(*L)->prox, D);
        return S || P;
    }

    NoDup *new = (NoDup *) malloc(sizeof(NoDup));

    if (new != NULL){
        switch((*L)->tipo){
            case Real:
                new->info.f = (*L)->info.atom.f;
                break;
            
            case Int:
                new->info.i = (*L)->info.atom.i;
                break;
            
            case Char:
                new->info.c = (*L)->info.atom.c;
                break;
        }

        new->tipo = (*L)->tipo;

        new->esq = (*D)->esq;
        new->dir = *D;

        (*D)->esq->dir = new;
        (*D)->esq = new;

        return Converter(&(*L)->prox, D);
    } else {
        return 0;
    }
}

void LD_aux(NoDup *p){
    if (p->tipo == -1) return;

    switch(p->tipo){
        case Real:
            printf("%.2f", p->info.f);
            break;
        
        case Int:
            printf("%d", p->info.i);
            break;
        
        case Char:
            printf("%c", p->info.c);
            break;
    }

    if (p->dir->tipo != -1) printf(", ");

    LD_aux(p->dir);
}

void ListaDup_print(ListaDup *D){
    printf("(");

    LD_aux(D->ini->dir);

    printf(")\n");
}
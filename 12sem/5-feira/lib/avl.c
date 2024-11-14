#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criar(){
	AVL *A = (AVL *) malloc(sizeof(AVL));
	
	if (A != NULL)
		A->raiz = NULL;
		
	return A;
}

No *procurar_pai(No *a, elem x){
	if (a == NULL) return a;
	
	if (a->info <= x && a->dir != NULL)
		return procurar_pai(a->dir, x);
	else if (a->info > x && a->esq != NULL)
		return procurar_pai(a->esq, x);
	
	return a;
}

void rotacao_dir(No **a){
	No *b = (*a)->esq;
	
	(*a)->FB++;
	b->FB++;
	
	(*a)->esq = b->dir;
	b->dir = *a;
	*a = b;
}

void rotacao_esq(No **a){
	No *b = (*a)->dir;
	
	(*a)->FB--;
	b->FB--;
	
	(*a)->dir = b->esq;
	b->esq = *a;
	*a = b;
}

int rebalanceamento(No **atual, No *pai){
	if ((*atual) == NULL) return 0; // Nao encontrou o pai
	if ((*atual) == pai) return 1; // Encontrou o pai
	
	if (rebalanceamento(&(*atual)->esq, pai))
		(*atual)->FB--;
	else if (rebalanceamento(&(*atual)->dir, pai))
		(*atual)->FB++;

	if ((*atual)->FB <= -2){
		if ((*atual)->esq->FB * (*atual)->FB >= 0) { // Mesmo sinal -> Rotacao simples
			rotacao_dir(atual);
		} else { // Troca de sinal -> Rotacao dupla
			rotacao_esq(&(*atual)->esq);
			rotacao_dir(atual);
		}
		
		return 1; // Acabou o rebalanceamento
	} else if ((*atual)->FB >= 2){
		if ((*atual)->dir->FB * (*atual)->FB >= 0) { // Mesmo sinal -> Rotacao simples
			rotacao_esq(atual);
		} else { // Troca de sinal -> Rotacao dupla
			rotacao_dir(&(*atual)->dir);
			rotacao_esq(atual);
		}
		
		return 1; // Acabou o rebalanceamento
	}
	
	return 1; // Backtracking
}

int inserir(AVL *A, elem x){
	No *pai = procurar_pai(A->raiz, x);
	
	if (pai != NULL && pai->info == x) // Elemento ja existe na AVL
		return 0; // Nao inserido
	
	No *filho = (No *) malloc(sizeof(No));
	
	if (filho != NULL){
		filho->info = x;
		filho->FB = 0;
		filho->esq = filho->dir = NULL;
		
		if (pai == NULL){ // Sem elementos
			A->raiz = filho;
		} else {
			if (pai->info > x){
				pai->esq = filho;
				pai->FB--;
			} else {
				pai->dir = filho;
				pai->FB++;
			}
			
			rebalanceamento(&A->raiz, pai);
		}
		
		return 1; // Inserido
	}
	
	return -1; // Memoria insuficiente
}

void rec_print(No *p){
	if (p == NULL) return;
	
	printf(FORMAT, p->info);
	
	// profundidade
	/*
	if (p->esq != NULL) printf(", ");
	rec_print(p->esq);
	if (p->dir != NULL) printf(", ");
	rec_print(p->dir);
	*/
	
	// individual
	if (p->esq != NULL) printf(": esq=%d", p->esq->info);
	if (p->dir != NULL) printf(", dir=%d", p->dir->info);
	printf(" (%d)\n", p->FB);
	
	rec_print(p->esq);
	rec_print(p->dir);
}

void print(char *pre, AVL *A, char *pos){
	printf("%s", pre);
	
	rec_print(A->raiz);
	
	printf("%s", pos);
}
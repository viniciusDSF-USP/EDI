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
	
	(*a)->esq = b->dir;
	b->dir = *a;
	*a = b;
}

void rotacao_esq(No **a){
	No *b = (*a)->dir;
	
	(*a)->dir = b->esq;
	b->esq = *a;
	*a = b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int calcFB(No **p){
	if ((*p) == NULL) return 0;
	
	int E = calcFB(&(*p)->esq);
	int D = calcFB(&(*p)->dir);
	
	(*p)->FB = D - E;
	
	return 1 + max( E, D );
}

int rebalanceamento(No **atual, No *pai){
	if ((*atual) == NULL) return 0; // Nao encontrou o pai
	if ((*atual) == pai) return 1; // Encontrou o pai
	
	int E = rebalanceamento(&(*atual)->esq, pai);
	int D = rebalanceamento(&(*atual)->dir, pai);
	
	if (E != 1 && D != 1) return 0;

	if ((*atual)->FB <= -2){
		if ((*atual)->esq->FB * (*atual)->FB >= 0) { // Mesmo sinal -> Rotacao simples
			rotacao_dir(atual);
		} else { // Troca de sinal -> Rotacao dupla
			rotacao_esq(&(*atual)->esq);
			rotacao_dir(atual);
		}
		
		return 0; // Acabou o rebalanceamento
	} else if ((*atual)->FB >= 2){
		if ((*atual)->dir->FB * (*atual)->FB >= 0) { // Mesmo sinal -> Rotacao simples
			rotacao_esq(atual);
		} else { // Troca de sinal -> Rotacao dupla
			rotacao_dir(&(*atual)->dir);
			rotacao_esq(atual);
		}
		
		return 0; // Acabou o rebalanceamento
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
			} else {
				pai->dir = filho;
			}
			
			calcFB(&A->raiz);
			rebalanceamento(&A->raiz, pai);
			calcFB(&A->raiz);
		}
		
		return 1; // Inserido
	}
	
	return -1; // Memoria insuficiente
}

void rec_print(No *p, int space){
	if (p == NULL) return;
	
	space += LINE;
	
	rec_print(p->dir, space);
	
	printf("\n");
	for (int i=LINE; i<space; i++)
		printf(" ");
	printf("%d(%d)", p->info, p->FB);
	printf("\n");
	
	rec_print(p->esq, space);
}

void print(char *pre, AVL *A, char *pos){
	printf("%s", pre);
	
	rec_print(A->raiz, 0);
	
	printf("%s", pos);
}
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criar(){
	AVL *A = (AVL *) malloc(sizeof(AVL));
	
	if (A != NULL)
		A->raiz = NULL
		
	return A;
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
			
			rebalanceamento(A->raiz, pai, filho);
		}
		
		return 1; // Inserido
	}
	
	return -1; // Memoria insuficiente
}

No *procurar_pai(No *a, elem x){
	if (a == NULL) return a;
	
	if (a->info <= x && a->dir != NULL)
		procurar_pai(a->dir, x);
	else if (a->info > x && a->esq != NULL)
		procurar_pai(a->esq, x);
	
	return a;
}

No *rebalanceamento(No *atual, No *pai, No *filho){
	if (atual == NULL) return NULL;
	if (atual == pai) return atual;
	
	No *back;
	
	back = rebalanceamento(atual->esq, pai, filho);
	if (back != NULL) atual->FB--;

	back = rebalanceamento(atual->dir, pai, filho);
	if (back != NULL) atual->FB++;
	
	if (atual->FB == -2){
		if (back->FB*atual->FB >= 0) { // Mesmo sinal -> Rotacao simples
			rotacao_dir(&atual, &back);
		} else { // Troca de sinal -> Rotacao dupla
			rotacao_esq(&back);
			rotacao_dir(&back);
		}
	}
	
	return atual;
}

void rotacao_dir(No **avo, No **pai){
	No *aux;
	
	a
}
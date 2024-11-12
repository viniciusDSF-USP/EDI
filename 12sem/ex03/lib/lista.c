#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *cria(){
	Lista *L = (Lista *) malloc(sizeof(Lista));
	
	if (L != NULL){
		No *head = (No *) malloc(sizeof(No));
		
		if (head != NULL){
			head->info = -1;
			head->esq = head->dir = head;
			
			L->ini = head;
		} else {
			free(L);
			return NULL;
		}
	}
	
	return L;
}

int esta_vazia(Lista *L){
	return L->ini->dir->info == -1;
}

int esta_na_lista(Lista *L, elem x){
	No *p = L->ini->dir;
	
	while (p->info != -1){
		if (p->info == x) return 1;
	
		p = p->dir;
	}
	
	return 0;
}

int insere_a_direita_de(Lista *L, elem x, elem y){
	if (x == -1) return 0;
	
	No *p = L->ini->dir;
	
	while (p->info != -1 && p->info != y){
		p = p->dir;
	}
	
	No *new = (No *) malloc(sizeof(No));
		
	if (new != NULL){
		new->info = x;
		new->esq = p;
		new->dir = p->dir;
		
	} else return 0;
	
	if (esta_vazia(L)){ //
		p->esq->dir = new;
		p->esq = new;
	} else {
		p->dir->esq = new;
		p->dir = new;
	}
}

void print(char *pre, Lista *L, char *pos){
	printf("%s", pre);
	
	No *p = L->ini->dir;
	while (p->info != -1){
		printf(FORMAT, p->info);
		
		if (p->dir->info != -1) printf(", ");
		p = p->dir;
	}
	
	printf("%s", pos);
}
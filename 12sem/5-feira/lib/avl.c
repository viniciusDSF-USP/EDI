#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criar(){
	AVL *A = (AVL *) malloc(sizeof(AVL));
	
	if (A != NULL) A->raiz = NULL;
	
	return A;
}

int altura(No *p){
	if (p == NULL) return 0;
	return p->altura;
}

int max(int a, int b){
	return a > b ? a : b;
}

void rot_esq(No **a){
	No *b = (*a)->dir;
	
	(*a)->dir = b->esq;
	b->esq = *a;
	
	(*a)->altura = max( altura((*a)->esq), altura((*a)->dir) )+1;
	b->altura = max( altura(b->esq), altura(b->dir) )+1;
	
	(*a)->FB = altura((*a)->dir) - altura((*a)->esq);
	b->FB = altura(b->dir) - altura(b->esq);
	
	*a = b;
}

void rot_dir(No **a){
	No *b = (*a)->esq;
	
	(*a)->esq = b->dir;
	b->dir = *a;
	
	(*a)->altura = max( altura((*a)->esq), altura((*a)->dir) )+1;
	b->altura = max( altura(b->esq), altura(b->dir) )+1;
	
	(*a)->FB = altura((*a)->dir) - altura((*a)->esq);
	b->FB = altura(b->dir) - altura(b->esq);
	
	*a = b;
}

int inserir(No **p, elem x){
	if (*p == NULL){
		No *new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = x;
			new->FB = 0;
			new->altura = 1;
			new->esq = new->dir = NULL;
			
			*p = new;
		}
		
		return 1;
	}
	
	int E = 0, D = 0;
	
	if (x < (*p)->info)
		E = inserir(&(*p)->esq, x);
	else if (x > (*p)->info)
		D = inserir(&(*p)->dir, x);
	else
		return 0;
	
	if (E || D){
		(*p)->altura++;
		(*p)->FB = altura((*p)->dir) - altura((*p)->esq);
	}
	
	if ((*p)->FB <= -2){
		if ((*p)->esq->FB > 0)
			rot_esq(&(*p)->esq);
		rot_dir(p);
	} else if ((*p)->FB >= 2){
		if ((*p)->dir->FB < 0)
			rot_dir(&(*p)->dir);
		rot_esq(p);
	}
	
	return (E || D);
}

void print_rec(No *p, int space){
	if (p == NULL) return;
	
	space += S;
	
	print_rec(p->dir, space);
	
	printf("\n");
	for (int i=S; i<=space; i++)
		printf(" ");
	
	printf("%d(%d)\n", p->info, p->FB);
	
	print_rec(p->esq, space);
}

void print(char *pre, No *p, char *pos){
	printf("%s", pre);
	
	print_rec(p, 0);
	
	printf("%s", pos);
}
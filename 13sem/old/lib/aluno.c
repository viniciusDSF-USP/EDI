#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno *criar_Aluno(){
	Aluno *A = (Aluno *) malloc(sizeof(Aluno));
	
	if (A != NULL){
		A->raiz = NULL;
	}
	
	return A;
}

int altura_aluno(No_Aluno *a){
	if (a == NULL) return 0;
	return a->altura;
}

int max(int a, int b){
	return a > b ? a : b;
}

void rot_esq_aluno(No_Aluno **a){
	No_Aluno *b = (*a)->dir;
	
	// Rotacao
	(*a)->dir = b->esq;
	b->esq = *a;
	
	// Recalculando a altura_aluno e o AB
	(*a)->altura = max( altura_aluno((*a)->esq), altura_aluno((*a)->dir) )+1;
	b->altura = max( altura_aluno(b->esq), altura_aluno(b->dir) )+1;
	
	(*a)->FB = altura_aluno((*a)->dir) - altura_aluno((*a)->esq);
	b->FB = altura_aluno(b->dir) - altura_aluno(b->esq);
	
	// Quando 'a' eh a raiz, 'b' passa a ser a raiz
	*a = b;
}

void rot_dir_aluno(No_Aluno **a){
	No_Aluno *b = (*a)->esq;
	
	// Rotacao
	(*a)->esq = b->dir;
	b->dir = *a;
	
	// Recalculando a altura_aluno e o AB
	(*a)->altura = max( altura_aluno((*a)->esq), altura_aluno((*a)->dir) )+1;
	b->altura = max( altura_aluno(b->esq), altura_aluno(b->dir) )+1;
	
	(*a)->FB = altura_aluno((*a)->dir) - altura_aluno((*a)->esq);
	b->FB = altura_aluno(b->dir) - altura_aluno(b->esq);
	
	// Quando 'a' eh a raiz, 'b' passa a ser a raiz
	*a = b;
}

int inserir_aluno(No_Aluno **a, char *nome, int nroUSP){
	if (*a == NULL) {
		No_Aluno *new = (No_Aluno *) malloc(sizeof(No_Aluno));
		
		if (new != NULL){
			new->nome = (char *) malloc(STRLIM * sizeof(char));
			
			if (new->nome == NULL){
				free(new);
				return 0;
			} else {
				strcpy(new->nome, nome);
			}
			
			new->nroUSP = nroUSP;
			new->altura = 1;
			new->FB = 0;
			
			new->filmes_pred = (Lista *) malloc(sizeof(Lista));
			
			if (new->filmes_pred == NULL) {
				free(new);
				return 0;
			} else {
				new->filmes_pred->ini = NULL;
			}
			
			new->esq = new->dir = NULL;
			
			*a = new;
			return 1;
		} else {
			return 0;
		}
	}
	
	int E = 0, D = 0;
	
	if (strcmp(nome, (*a)->nome) <= -1) // nome < (*a)->nome
		E = inserir_aluno(&(*a)->esq, nome, nroUSP);
	else if (strcmp(nome, (*a)->nome) >= 1) // nome > (*a)->nome
		D = inserir_aluno(&(*a)->dir, nome, nroUSP);
	else { // nome == (*a)->nome
		return 0;
	}
	
	if (E || D){
		(*a)->altura++;
		(*a)->FB = altura_aluno((*a)->dir) - altura_aluno((*a)->esq);
	}
	
	if ((*a)->FB <= -2){
		if ((*a)->esq->FB > 0)
			rot_esq_aluno(&(*a)->esq);
		rot_dir_aluno(a);
	} else if ((*a)->FB >= 2){
		if ((*a)->dir->FB < 0)
			rot_dir_aluno(&(*a)->dir);
		rot_esq_aluno(a);
	}
	
	return (E || D);
}

No_Aluno **buscar_aluno(No_Aluno **a, int nroUSP){
	if (*a == NULL) return NULL;
	
	if (nroUSP < (*a)->nroUSP)
		buscar_aluno(&(*a)->esq, nroUSP);
	else if (nroUSP > (*a)->nroUSP)
		buscar_aluno(&(*a)->dir, nroUSP);
	else
		return a;
}

void limpar_Aluno(No_Aluno **a){
	if (*a == NULL) return;
	
	if ((*a)->esq == NULL && (*a)->dir == NULL) // Se for uma folha
		free(*a);
	else {
		limpar_Aluno(&(*a)->esq);
		limpar_Aluno(&(*a)->dir);
	}
	
	*a = NULL; // Raiz vira NULL
	
	return;
}

void rec_print_aluno(No_Aluno *a, int spaces){
	if (a == NULL) return;
	
	spaces += TAB;
	
	rec_print_aluno(a->dir, spaces);
	
	printf("\n");
	for (int i=TAB; i<=spaces; i++)
		printf(" ");
		
	printf("%s(%d)\n", a->nome, a->nroUSP);
	
	rec_print_aluno(a->esq, spaces);
}

void print_arvore(char *pre, No_Aluno *a, char *pos){
	printf("%s", pre);
	
	rec_print_aluno(a, 0);
	
	printf("%s", pos);
}

void print_filmes(char *pre, No_Lista *l, char *pos){
	printf("%s", pre);
	
	while (l != NULL){
		printf("%s", l->nome);
		if (l->prox != NULL) printf(", ");
		
		l = l->prox;
	}
	
	printf("%s", pos);
}

void print_aluno(char *pre, No_Aluno **a, int nroUSP, char *pos){
	No_Aluno **aluno = buscar_aluno(a, nroUSP);
	
	printf("%s", pre);
	
	if (*aluno != NULL) {
		printf("Nome: %s\n", (*aluno)->nome);
		printf("Numero USP: %d\n", (*aluno)->nroUSP);
		print_filmes("Filmes prediletos: {", (*aluno)->filmes_pred->ini, "}\n");
	}
	
	printf("%s", pos);
}

int inserir_lista(No_Lista **l, char *nome){
	No_Lista *new = (No_Lista *) malloc(sizeof(No_Lista));
	
	if (new != NULL){
		new->nome = (char *) malloc(STRLIM * sizeof(char));
			
		if (new->nome == NULL){
			free(new);
			return 0;
		} else {
			strcpy(new->nome, nome);
		}
		
		new->prox = NULL;
		
		No_Lista **aux = l;
		
		while (*l != NULL && strcmp((*l)->nome, nome) < 0){
			aux = l;
			l = &(*l)->prox;
		}
		
		if (*aux == NULL) *aux = new;
		else if (aux == l) { // Nao tem elementos menores que new
			new->prox = *aux;
			*aux = new;
		} else {
			new->prox = (*aux)->prox;
			(*aux)->prox = new;
		}
		
		return 1;
	} else {
		return 0;
	}
}

int inserir_filme(No_Aluno **a, int nroUSP, char *nome){
	No_Aluno **aluno = buscar_aluno(a, nroUSP);
	
	if (*aluno != NULL) {
		return inserir_lista(&(*aluno)->filmes_pred->ini, nome);
	} else {
		return 0;
	}
}

int remover_lista(No_Lista **l, char *nome){
	while (*l != NULL){
		if ((*l)->prox != NULL && strcmp((*l)->prox->nome, nome) == 0)
			break;
		l = &(*l)->prox;
	}
	
	if (*l != NULL){
		No_Lista *aux = (*l)->prox;
		
		(*l)->prox = aux->prox;
		free(aux);
		
		return 1;
	} else {
		return 0;
	}
}

int remover_filme(No_Aluno **a, int nroUSP, char *nome){
	No_Aluno **aluno = buscar_aluno(a, nroUSP);
	
	if (*aluno != NULL) {
		return remover_lista(&(*aluno)->filmes_pred->ini, nome);
	} else {
		return 0;
	}
}
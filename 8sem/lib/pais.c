#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

void Create(Lista *L){
	L->ini = L->fim = NULL;
}

int AddPai(Lista *L, long long int cpf, char nome[]){
	Pai *ant, *curr, *new;

	new = (Pai *) malloc(sizeof(Pai));
	if (new == NULL) return 0;
	strcpy(new->nome, nome);
	new->cpf = cpf;

	curr = L->ini;
	while (curr != NULL){
		if (curr->cpf == cpf) {
			free(new);
			return 0;
		} else if (curr->cpf > cpf){
			if (ant == NULL){
				new->prox = L->ini;
				L->ini = new;
			} else {
				ant->prox = new;
				new->prox = curr;
			}
			return 1;
		}
		ant = curr;
		curr = curr->prox;
	}

	if (L->ini == NULL){ // vazia
		L->ini = L->fim = new;
	} else { // curr estah no L->fim
		L->fim = L->fim->prox = new;
	}

	return 1;
}

Pai *FindPai(Lista *L, long long int cpf){
	Pai *curr = L->ini;

	while (curr != NULL){
		if (curr->cpf == cpf) break;
		curr = curr->prox;
	}

	return curr;
}

void printL(Lista *L){
    Pai *curr = L->ini;
    int i=0;

	while (curr != NULL){
		printf("%d | %s | %lld\n", i, curr->nome, curr->cpf);
		curr = curr->prox;
		i++;
	}
}

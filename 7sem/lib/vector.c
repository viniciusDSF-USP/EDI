#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector *vecCreate(vector *v, int *err){
	v = (vector *) malloc(sizeof(vector));

	if (v == NULL) {
		*err = 1;
	} else {
		v->ini = NULL;
		v->fim = NULL;
		*err = 0;
	}

	return v;
}

void vecPush_back(vector *v, int x, int *err){
	no *u = (no *) malloc(sizeof(no));

	if (u == NULL){
		*err = 1;
		return;
	}

	u->info = x;
	*err = 0;

	if (v->ini == NULL){
		v->ini = v->fim = u;
	} else {
		v->fim = v->fim->prox = u;
	}

	return;
}

void vecDelete(vector *v, int x, int *err){
	no *ptr, *aux;

	ptr = v->ini;

	if (v->ini->info == x){ // deleta inicio
		v->ini = v->ini->prox;
		free(ptr);
		*err = 0;
		return;
	} else {
		while (ptr->prox != NULL){
			if (ptr->prox->info == x){ // deleta nao inicio
				aux = ptr->prox;

				if (ptr->prox == v->fim){ // deleta fim
					v->fim = ptr;
				}
				ptr->prox = ptr->prox->prox;

				free(aux);
				*err = 0;
				return;
			}
			ptr = ptr->prox;
		}
	}

	*err = 1;
	return;
}

no *vecFind(vector *v, int x, int *err){
	no *ptr = v->ini;

	while (ptr != NULL){
		if (ptr->info == x){
			*err = 0;
			return ptr;
		}
		ptr = ptr->prox;
	}

	*err = 1;
	return ptr;
}

int vecLen(vector *v){
	no *ptr = v->ini;
	int len=0;

	while (ptr != NULL){
		len++;
		ptr = ptr->prox;
	}

	return len;
}

void vecClear(vector *v){
	no *ptr, *aux;

	ptr = v->ini;

	while (ptr != NULL){
		v->ini = ptr->prox;
		free(ptr);
		ptr = v->ini;
	}

	v->fim = NULL;
	return;
}

void vecPrint(vector *v){
	no *ptr = v->ini;

	while (ptr != NULL){
		printf("%d", ptr->info);
		if (ptr->prox != NULL) printf(", ");
		ptr = ptr->prox;
	}
	printf("\n");

	return;
}

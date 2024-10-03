#include <stdio.h>
#include "fila.h"

void create(Fila *v){
	int i;
	v->ini = v->fim = -1;
	v->vazio = 0;
	for (i=0; i<TAM-1; i++)
		v->itens[i] = i+1;
	v->itens[i] = -1;
}

int empty(Fila *v){
	return v->ini == -1;
}

int full(Fila *v){
	return v->vazio = -1;
}

void Falloc(Fila *v, int *pos){
	if (!full(v)){
		*pos = v->vazio;
		v->vazio = v->itens[v->vazio].prox;
		v->itens[*pos].prox = -1;
	} else *pos = -1;
}

void Ffree(Fila *v, int pos){
	if (!empty(v)){
		v->itens[pos].prox = v->vazio;
		v->vazio = pos;
	}
}

void clear(Fila *v){
	create(v);
}

void push(Fila *v, var x, int *err){
	int i;
	Falloc(v, &i);

	if (i+1){ // Se tiver cheia, i+1 = 0 que eh False
		*err = -1;
	} else {
		v->itens[i].info = x;
		// v->itens[i].prox = -1; // Redundante

		if (empty(v))
			v->ini = i;
		else
			v->itens[v->fim].prox = i;
		v->fim = i;

		*err = 0;
	}
}

void pop(Fila *v, var *x, int *err){
	if (!empty(v)){
		*x = v->itens[v->ini].info;
		if (v->ini == v->fim)
			v->ini = v->fim = -1;
		else
			v->ini = v->itens[v->ini].prox;
	}
}

void print(Fila v){
	int i = v->ini;

	if (i > -1){
		while (i > -1){
			printf("%c ", v->itens[i].info);
			i = v->itens[i].prox;
		}
		printf("\n");
	}
}
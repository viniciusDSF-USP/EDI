#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define NO_ERR 0
#define ALLOC_ERR 1
#define FULL_ERR 2
#define EMPTY_ERR 3

stack *Create(int *err){
	stack *x = (stack *) malloc(sizeof(stack));
	if (x == NULL) *err = ALLOC_ERR;
	else {
		x->topo = -1;
		*err = NO_ERR;
	}
	return x;
}

void alloc(stack *s, int *err){
	for (int i=0; i<TAM; i++){
		s->itens[i] = (type) malloc(TAM * sizeof(subtype));
		if (s->itens[i] == NULL) {
			*err = ALLOC_ERR;
			break;
		} else {
			for (int j=0; j<TAM; j++) s->itens[i][j] = varempty;
			*err = NO_ERR;
		}
	}
	return;
}

void check(int *err){
	switch (*err) {
		case NO_ERR:
			break;

		case ALLOC_ERR:
			printf("\nErro de alocacao!\n");
			exit(0);

		case FULL_ERR:
			printf("\nA pilha esta cheia!\n");
			break;

		case EMPTY_ERR:
			printf("\nA pilha esta vazia!\n");
			break;

		default:
			break;
	}
	return;
}

int Empty(stack *s){
	return (s->topo == -1);
}

int Full(stack *s){
	return (s->topo == TAM-1);
}

void Push(stack *s, type x, int *err){
	if (!Full(s)) {
		s->itens[++s->topo] = x;
		*err = NO_ERR;
	} else *err = FULL_ERR;
	return;
}

void SubPush(stack *s, subtype x, int *err){
	if (!Full(s)) {
		s->topo++;
		for (int i=0; i<TAM; i++)
			if (s->itens[s->topo][i] == varempty){
				s->itens[s->topo][i] = x;
				if (i < TAM-1) s->itens[s->topo][i+1] = '\0';
				break;
			}
		*err = NO_ERR;
	} else *err = FULL_ERR;
	return;
}

type Top(stack *s, int *err){
	if (!Empty(s)) return s->itens[s->topo];
	else {
		*err = EMPTY_ERR;
		return (type)0;
	}
}

void Pop(stack *s, int *err){
	if (!Empty(s)) s->topo--;
	else *err = EMPTY_ERR;
	return;
}

int Size(stack *s){
	return s->topo+1;
}

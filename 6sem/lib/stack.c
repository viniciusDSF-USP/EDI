#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stackCreate(stack *P){
	P->topo = -1;
	return;
}

int stackEmpty(stack *P){
	return P->topo == -1;
}

int stackFull(stack *P){
	return P->topo == TAM-1;
}

void stackPush(stack *P, int x, int *err){
	if (stackFull(P)) *err = 1;
	else {
		P->itens[++P->topo] = x;
		*err = 0;
	}
	return;
}

void stackPop(stack *P, int *x, int *err){
	if (stackEmpty(P)) *err = 1;
	else {
		*x = P->itens[P->topo--];
		*err = 0;
	}
	return;
}

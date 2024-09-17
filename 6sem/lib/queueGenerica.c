#include <stdio.h>
#include <stdlib.h>
#include "queueGenerica.h"

void Create(queue *F){
	F->ini = F->fim = F->total = 0;
	return;
}

void Clear(queue *F){
	F->ini = F->fim = F->total = 0;
	return;
}

int Empty(queue *F){
	return F->total == 0;
}

int Full(queue *F){
	return F->total == TAM;
}

void Push(queue *F, var x, int *err){
	if (Full(F)) *err = 1;
	else {
		F->itens[F->fim] = x;
		F->fim = (++F->fim)%TAM;
		F->total++;
		*err = 0;
	}
	return;
}

void Front(queue *F, var *x, int *err){
	if (Empty(F)) *err = 1;
	else {
		*x = F->itens[F->ini];
		F->ini = (++F->ini)%TAM;
		F->total--;
		*err = 0;
	}
}

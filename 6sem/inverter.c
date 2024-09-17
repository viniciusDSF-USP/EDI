#include <stdio.h>
#include <stdlib.h>
#include "lib/queue.h"
#include "lib/stack.h"

void Inverter(queue *F){
	int err;
	stack aux;
	stackCreate(&aux);

	int x;
	while (!Empty(F)){
		Front(F, &x, &err); // esvazia a fila
		stackPush(&aux, x, &err); // empilha
	}

	while (!stackEmpty(&aux)){
		stackPop(&aux, &x, &err); // desempilha
		Push(F, x, &err); // inverte a lista
	}

	return;
}

int main(){
	int err=0;
        queue A;

        Create(&A);

        Push(&A, 0, &err);
        Push(&A, 1, &err);
        Push(&A, -2, &err);
        Push(&A, 4, &err);
        Push(&A, 9, &err);

	Inverter(&A);

	int x;
	while (!Empty(&A)){
		Front(&A, &x, &err);
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}

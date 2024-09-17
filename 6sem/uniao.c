#include <stdio.h>
#include <stdlib.h>
#include "lib/queue.h"

void sort(int *v, int n){
	for (int i=1, j=0, k=0, aux; i<n; i++){
		j = i;
		k = j-1;
		while (j >= 0 && k >= 0 && v[k] > v[j]){
			aux = v[j];
			v[j--] = v[k];
			v[k--] = aux;
		}
	}
	return;
}

queue UniaoCrescente(queue A, queue B){
	int err=0, a, b, i=0;
	int v[TAM], n;
	queue C;
	Create(&C);

	while (!Empty(&A) || !Empty(&B)){
		Front(&A, &a, &err);
		if (!err && i < TAM) v[i++] = a;

		Front(&B, &b, &err);
		if (!err && i < TAM) v[i++] = b;

		n = i;
	}

	sort(v, n);
	for (int i=0; i<n; i++){
		Push(&C, v[i], &err);
	}

	return C;
}

int main(){
	int err=0;
	queue A, B, C;

	Create(&A);
	Create(&B);

	Push(&A, 0, &err);
	Push(&A, 1, &err);
	Push(&A, -2, &err);
	Push(&A, 4, &err);
	Push(&A, 9, &err);

	Push(&B, 0, &err);
	Push(&B, 1, &err);
	Push(&B, 4, &err);
	Push(&B, 1, &err);
	Push(&B, 0, &err);
	Push(&B, -2, &err);

	C = UniaoCrescente(A, B);

	type x;
	while (!Empty(&C)){
		Front(&C, &x, &err);
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}

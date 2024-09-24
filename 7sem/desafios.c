#include <stdio.h>
#include <stdlib.h>
#include "lib/vector.h"

int somaI(vector *L);
int somaR(vector *L);
void sort(vector *L);

int main(){
	int err=0;
	vector *L = vecCreate(L, &err);

	for (int i=1; i<=100; i++){
		vecPush_back(L, i, &err);
	}

	printf("%d %d\n", somaI(L), somaR(L));

	vecClear(L);
	vecPush_back(L, 2, &err);
	vecPush_back(L, 8, &err);
	vecPush_back(L, 11, &err);
	vecPush_back(L, -10, &err);
	vecPush_back(L, 0, &err);

	vecPrint(L);
	sort(L);
	vecPrint(L);

	return 0;
}

int somaI(vector *L){
	no *ptr = L->ini;
	int sum=0;

	while (ptr != NULL){
		sum += ptr->info;
		ptr = ptr->prox;
	}

	return sum;
}

int _auxsomaR(no *u){
	if (u == NULL) return 0;
	return u->info + _auxsomaR(u->prox);
}

int somaR(vector *L){
	no *ptr = L->ini;

	return _auxsomaR(ptr);
}

void sort(vector *L){
	no *pivo = L->fim;
	no *i, *j, *mid;
	i = j = L->ini;
	int aux;

	while (i != NULL){
		if (i->info <= pivo->info){
			aux = i->info;
			i->info = j->info;
			j->info = aux;

			mid = j;
			j = j->prox;
		}

		i = i->prox;
	}

	_sort(L->ini, mid);
	_sort(mid->prox, L->fim);

	return;
}
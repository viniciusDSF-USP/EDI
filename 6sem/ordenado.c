#include <stdio.h>
#include <stdlib.h>
#include "lib/queue.h"

int Crescente(queue F){
	type old, x;
	int err;

	Front(&F, &old, &err);
	while (!Empty(&F)){
		Front(&F, &x, &err);
		if (x < old) return 0;
		old = x;
	}
	return 1;
}

int main(){
	int err;
	queue F;

	Create(&F);
	for (int i=0; i<TAM-1; i++) Push(&F, i, &err);
	printf("%d\n", Crescente(F));

	Push(&F, 2, &err);
	printf("%d\n", Crescente(F));

	return 0;
}

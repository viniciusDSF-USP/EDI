#include <stdio.h>
#include <stdlib.h>
#include "lib/vector.h"

int main(){
	int err=0;
	vector *L = vecCreate(L, &err);

	for (int i=0; i<92; i++){
		vecPush_back(L, i+1, &err);
	}

	vecFind(L, 91, &err);
	printf("%d\n", !err);

	vecFind(L, 94, &err);
	printf("%d\n", !err);

	printf("%d\n", vecLen(L));

	vecDelete(L, 31, &err);

	printf("L: ");
	vecPrint(L);

	vecClear(L);
	printf("L: ");
	vecPrint(L);

	return 0;
}

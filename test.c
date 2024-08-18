#include <stdio.h>
#include <stdlib.h>
#include "bigmath.c"

int main(){
	char* n = str(1), *m = str(1);

	scanf("%s %s", n, m);

	printf("%s\n", BigDiv(n,m));

	return 0;
}

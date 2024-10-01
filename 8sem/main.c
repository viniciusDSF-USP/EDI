#include <stdio.h>
#include <stdlib.h>
#include "lib/pais.h"

int main(){
	Lista L;
	Create(&L);

	printf("%d\n", AddPai(&L, 8273100521, "Arlindo Neto"));
	printf("%d\n", AddPai(&L, 2273100521, "Arlindo Correia"));
	printf("%d\n", AddPai(&L, 2273100521, "Pedro Correia"));

	printL(&L);
	printf("%s\n", FindPai(&L, 2273100521)->nome);

	return 0;
}

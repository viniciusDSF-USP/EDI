#include <stdio.h>
#include <stdlib.h>
#include "lib/lista.h"

int main(){
	Lista *L;
	
	L = cria();
	
	print("L = [", L, "]\n");
	printf("L esta vazia: %s\n", esta_vazia(L) ? "True" : "False");
	printf("2 esta na lista L: %s\n\n", esta_na_lista(L, 2) ? "True" : "False");
	
	insere_a_direita_de(L, 2, -1);
	insere_a_direita_de(L, 0, -1);
	insere_a_direita_de(L, 4, 2);
	insere_a_direita_de(L, 5, 0);
	
	print("L = [", L, "]\n");
	printf("L esta vazia: %s\n", esta_vazia(L) ? "True" : "False");
	printf("2 esta na lista L: %s\n", esta_na_lista(L, 2) ? "True" : "False");

	return 0;
}
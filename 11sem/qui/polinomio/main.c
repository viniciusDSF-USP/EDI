#include <stdio.h>
#include <stdlib.h>
#include "lib/polinomio.h"

int main(){
	Pol *P1 = create();
	
	pushTermo(P1, 4);
	pushVar(P1, 'x', 2);
	pushVar(P1, 'y', 3);
	pushVar(P1, 'z', 1);
	
	pushTermo(P1, 3);
	pushVar(P1, 'x', 1);
	pushVar(P1, 'y', 1);
	
	pushTermo(P1, 5);
	pushVar(P1, 'w', 4); // Adicionei pra testar
	
	printf("P1 = ");
	print(P1);
	
	Dict *D = createDict(P1);
	
	printf("P1(");
	printDict(D, 'K');
	printf(") = ");
	print(P1);
	
	add(D, 'x', 1);
	add(D, 'y', 1);
	add(D, 'z', 1);
	add(D, 'w', 2); // Adicionei pra testar
	
	printf("\nP1(");
	printDict(D, 'V');
	printf(") = %d\n", eval(P1, D));
	
	// Testando se quebrou o polinomio ou o dicionario
	
	printf("\n");
	print(P1);
	printDict(D, 'K');
	printf(": ");
	printDict(D, 'V');
	printf("\n");

	return 0;
}
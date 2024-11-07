#include <stdio.h>
#include <stdlib.h>
#include "lib/polinomio.h"

int main(){
	Pol *P = criar();
	
	criarTermo(P, 4);
	pushVar(P, 'x', 2);
	pushVar(P, 'y', 3);
	pushVar(P, 'z', 1);
	
	criarTermo(P, 3);
	pushVar(P, 'x', 1);
	pushVar(P, 'y', 1);
	
	criarTermo(P, 5);
	
	printPol(P);
	
	Dict *D = criarDict();
	pushDict(D, 'x', 3);
	pushDict(D, 'y', 1);
	pushDict(D, 'z', 2);
	
	printf("p(3,1,2) = %d\n", eval(P, D));
	
	return 0;
}
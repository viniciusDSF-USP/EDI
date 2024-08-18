#include <stdio.h>
#include <stdlib.h>
#include "../bigmath.c"

void sol(char q);

int main(int argc, char* argv[]){
	switch(argc){
		case 1:
			printf("Insira o numero do exercicio.\n");
			return 0;
		default:
			break;
	}

	sol(argv[1][0]);
}

// Funcoes

void dois(){
	char* n = str(0);
	char* ans, *ans2;
	char* um = str(1);
	char* dois = str(2);

	// a)
	do {
		printf("a) n: ");
		scanf("%s", n);
	} while (cmp(n,um) == -1);

	ans = BigSum(um,n);
	ans2 = BigMult(ans,n);
	free(ans);

	ans = BigDiv(ans2,dois); // (1+n)*n/2
	printf("ans = ");
	BigPrint(ans);
	printf("\n\n");

	free(ans);
	free(ans2);

	// b)
}

void sol(char q){
	switch (q){
		case '2':
			dois();
			break;
	}

	return;
}

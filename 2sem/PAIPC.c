#include <stdio.h>
#include <stdlib.h>
#include "../bigmath.c"

void sol(char q);

int main(int argc, char* argv[]){
	switch(argc){
		case 1:
			printf("Insira o numero do exercicio.\n");
			break;
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

	// a)
	do {
		printf("a) n: ");
		scanf("%s", n);
	} while (cmp(n,um) == -1);

	ans = BigSum(1,n);
	ans2 = BigMult(ans,n);

	free(ans);
	ans = BigDiv(ans2,2);
	printf("ans = %s\n\n", ans);

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

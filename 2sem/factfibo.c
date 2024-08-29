#include <stdio.h>
#include <stdlib.h>
#include "../bigmath.c"

void Fibonacci(char* num, char* f1, char* f2){
	printf("%s", f1);
	if (cmp(f1, num) >= 0) {
		printf("}\n");
		return;
	}
	printf(", ");

	char* sum = BigSum(f1,f2);

	free(f1);
	Fibonacci(num, f2, sum);

	return;
}

int main(){
	char* n = (char*) malloc(MAX*sizeof(char));

	printf("Insira um inteiro para calculo do fatorial: ");
	scanf("%s", n);

	printf("\n%s! = ", n);
	BigPrint(fatorial(n));
	printf("\n");

	/*printf("\n\nInsira um inteiro para o limite superior de Fibonacci: ");
	scanf("%s", n);

	printf("\n[%s] = {", n);
	Fibonacci(n, str(0), str(1));*/

	return 0;
}

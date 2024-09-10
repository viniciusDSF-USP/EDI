#include <stdio.h>
#include <stdlib.h>
#include "lib/pilha.h"

#define split 8

int main(){
        // Conversao pra numero binario
	int err = 0;
	stack *s = Create(&err);
	check(&err);

	int n=0;
	printf("Insira um numero inteiro para ser convertido para binario: ");
	scanf("%d", &n);

	while (n != 0){
		Push(s, n%2, &err);
		check(&err);
		n /= 2;
	}

	int i=0;
	while (!Empty(s)){
		if (i > 0 && !(i%split)) printf(" ");
		printf("%d", Top(s, &err));
		check(&err);

		Pop(s, &err);
		check(&err);
		i++;
	}
	for (; i > split && (i%split); i++) printf("0");
	printf("\n");

        return 0;
}

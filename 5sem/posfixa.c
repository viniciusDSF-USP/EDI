#include <stdio.h>
#include <stdlib.h>
#include "lib/pilha.h"

int Operador(char c){
	char op[] = "+-*/^";
	for (int i=0; i<5; i++)
		if (c == op[i]) return 1;
	return 0;
}

void Imprimir(stack *s, int *err){
	stack t = *s;
	s = &t;

	printf("{");
	while (!Empty(s)){
		printf("%s", Top(s, err));
		if (Size(s) > 1) printf(", ");
		Pop(s, err);
	}
	printf("}\n");
}

int main(){
        // Notação posfixa
	int n;
	char *exp;

	printf("Insira a quantidade de caracteres da expressao: ");
	scanf("%d", &n);

	exp = (char *) malloc(n * sizeof(char));
	if (exp == NULL) {
		printf("\nErro de alocacao!\n");
	}

	printf("Insira a expressao em notacao posfixa: ");
	scanf("%s", exp);
	getchar();

	int er=0;
	int *err = &er;
	stack *s = Create(err);
	check(err);
	alloc(s, err);
	check(err);

	for (int i=0; i<n; i++){
		if (exp[i] == varempty) break;

		SubPush(s, exp[i], err);
		check(err);

		Imprimir(s, err);

		if (Operador(exp[i])){
			char *op = Top(s, err);
			Pop(s, err);
			check(err);

			char *b = Top(s, err);
			Pop(s, err);
			check(err);

			char *a = Top(s, err);
			check(err);

			for (int i=0,j=0,k=0; i<TAM; i++){ // a <op> b
				if (a[i] == '\0'){
					if (op[j] == '\0'){
						if (b[k] == '\0') break;
						a[i] = b[k++];
					} else {
						a[i] = op[j++];
					}
				}
			}

			if (!Empty(s)){
				for (int i=TAM-1; i>0; i--)
					a[i] = a[i-1];
				a[0] = '(';

				for (int i=0; i<TAM; i++)
					if (a[i] == varempty){
						a[i] = ')';
						break;
					}
			}
		}
	}

	printf("%s -> %s\n", exp, Top(s, err));
	check(err);

        return 0;
}

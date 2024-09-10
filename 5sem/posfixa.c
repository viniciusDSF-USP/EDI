#include <stdio.h>
#include <stdlib.h>
#include "lib/pilha.h"

int Operador(char c){
	char op[] = "+-*/^";
	for (int i=0; i<5; i++)
		if (c == op[i]) return 1;
	return 0;
}

int main(){
        // Notação posfixa
	char exp[] = "356*-";
	int n = 5;

	int er=0;
	int *err = &er;
	stack *s = Create(err);
	check(err);
	alloc(s, err);
	check(err);

	for (int i=0; i<n; i++){
		SubPush(s, exp[i], err);
		check(err);

		if (Operador(exp[i])){
			char *op = Top(s, err);
			Pop(s, err);
			check(err);

			char *b = Top(s, err);
			Pop(s, err);
			check(err);

			char *a = Top(s, err);
			check(err);

			printf("%s %s %s\n", a, op, b);

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
		}
	}

	printf("%s\n", Top(s, err));
	check(err);

        return 0;
}

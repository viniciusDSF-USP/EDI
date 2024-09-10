#include <stdio.h>
#include <stdlib.h>
#include "lib/pilha.h"

void Imprimir(stack *, int *);
int Iguais(stack *, stack *, int *);
stack *Inverter(stack *, int *);

int main(){
	int err=0;
	stack *s1 = Create(&err);
	check(&err);
	stack *s2 = Create(&err);
	check(&err);

	for (int i=0; i<10; i++) Push(s1, i, &err);
	for (int i=0; i<10; i++) Push(s2, i, &err);

        // Criar uma rotina para imprimir os elementos de uma pilha
	printf("s1 = ");
	Imprimir(s1, &err);
	printf("s2 = ");
	Imprimir(s2, &err);

        // Criar uma rotina para verificar se duas pilhas são iguais
	printf("\ns1 == s2: %c\n", Iguais(s1, s2, &err) ? 'S' : 'N');

        // Criar uma rotina para inverter a posição dos elementos de uma pilha
	s1 = Inverter(s1, &err);
	printf("\ns1 = ");
	Imprimir(s1, &err);

        return 0;
}

void Imprimir(stack *s, int *err){
	stack u = *s;
	stack *t = &u;

	printf("{");
	while (!Empty(t)){
		printf("%d", Top(t, err));
		if (Size(t) > 1) printf(", ");
		Pop(t, err);
	}
	printf("}\n");
	return;
}

int Iguais(stack *s, stack *t, int *err){
	stack s2 = *s;
	stack t2 = *t;

	s = &s2;
	t = &t2;

	int len1=Size(s), len2=Size(t);

	if (len1 != len2) return 0;
	else {
		while (!Empty(s)){
			if (Top(s, err) != Top(t, err)) return 0;
			Pop(s,err);
			check(err);
			Pop(t,err);
			check(err);
		}
		return 1;
	}
}

stack *Inverter(stack *s, int *err){
	stack *t = Create(err);
	check(err);

	while (!Empty(s)){
		Push(t, Top(s, err), err);
		check(err);
		Pop(s, err);
		check(err);
	}

	free(s);
	return t;
}

#include <stdio.h>
#include <stdlib.h>
#include "lib/lista.h"

int main(){
	ListaGen *L, *S, *S2;
	Elem x;
	
	L = criar();
	
	int exemplo = 1;
	switch (exemplo){
		case 1: // (f,(a,b),(c,(d,e)),())
			x.atom.c = 'f';
			push(L, x, t_char);
	
			S = criar();
			x.atom.c = 'a';
			push(S, x, t_char);
			x.atom.c = 'b';
			push(S, x, t_char);
			append(S, L);
	
			S2 = criar();
			x.atom.c = 'd';
			push(S2, x, t_char);
			x.atom.c = 'e';
			push(S2, x, t_char);
			S = criar();
			x.atom.c = 'c';
			push(S, x, t_char);
			append(S2, S);
			append(S, L);
			
			S = criar();
			append(S,L);
			break;
	
		case 2: // (a,b,c)
			x.atom.c = 'a';
			push(L, x, t_char);
	
			x.atom.c = 'b';
			push(L, x, t_char);
	
			x.atom.c = 'c';
			push(L, x, t_char);
			break;
	
		case 3: // ()
			break;
	}

	x.atom.c = 'e';
	printf("\"%c\" estah na lista: %s.\n", x.atom.c, busca(L, x, t_char) ? "SIM" : "NAO");
	printf("profundidade da lista: %d.\n", profundidade(L));
	
	ListaGen *L2;
	L2 = criar();

	x.atom.c = 'f';
	push(L2, x, t_char);
	
	S = criar();
	x.atom.c = 'a';
	push(S, x, t_char);
	x.atom.c = 'b';
	push(S, x, t_char);
	append(S, L2);
	
	S2 = criar();
	x.atom.c = 'd';
	push(S2, x, t_char);
	x.atom.c = 'e';
	push(S2, x, t_char);
	S = criar();
	x.atom.c = 'c';
	push(S, x, t_char);
	append(S2, S);
	append(S, L2);
	
	S = criar();
	append(S,L2);

	printf("L1 = L2: %s\n", iguais(L, L2) ? "SIM" : "NAO");

	return 0;
}
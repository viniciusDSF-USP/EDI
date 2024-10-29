#include <stdio.h>
#include <stdlib.h>
#include "lib/lista.h"

int main(){
	ListaGen* L = (ListaGen *) malloc(sizeof(ListaGen));
	Elem x;

	// (f,(a,b),(c,(d,e)),())
	No *p, *s, *t;
	x.atom.c = 'f'; L->ini = criarNo(x, t_char); // f

	p = L->ini;
	p->prox = criarNo(x, t_sublist); p = p->prox; s = p; // f -> (
	x.atom.c = 'a'; s->info.sub = criarNo(x, t_char); s = s->info.sub; // f -> (a
	x.atom.c = 'b'; s->prox = criarNo(x, t_char); s = s->prox; // f -> (a,b
	s->prox = NULL; // f -> (a,b)

	p->prox = criarNo(x, t_sublist); p = p->prox; s = p; // f -> (a,b) -> (
	x.atom.c = 'c'; s->info.sub = criarNo(x, t_char); s = s->info.sub; // f -> (a,b) -> (c
	s->prox = criarNo(x, t_sublist); s = s->prox; t = s; // f -> (a,b) -> (c,(
	x.atom.c = 'd'; t->info.sub = criarNo(x, t_char); t = t->info.sub; // f -> (a,b) -> (c,(d
	x.atom.c = 'e'; t->prox = criarNo(x, t_char); t = t->prox; // f -> (a,b) -> (c,(d,e
	t->prox = NULL; // f -> (a,b) -> (c,(d,e)
	s->prox = NULL; // f -> (a,b) -> (c,(d,e))

	p->prox = criarNo(x, t_sublist); p = p->prox; // f -> (a,b) -> (c,(d,e)) -> (
	p->prox = NULL; // f -> (a,b) -> (c,(d,e)) -> (), ou seja (f, (a,b), (c,(d,e)), ()) como queriamos

	x.atom.c = 'g';
	printf("\"%c\" estah na lista: %s.\n", x.atom.c, busca(L, x, t_char) ? "SIM" : "NAO");
	printf("profundidade da lista: %d.\n", profundidade(L));

	return 0;
}

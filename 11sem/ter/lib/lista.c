#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

ListaGen* criar(){
	ListaGen *L = (ListaGen *) malloc(sizeof(ListaGen));
	if (L != NULL){
		L->ini = NULL;
		L->fim = NULL;
	}
	return L;
}

void push(ListaGen* L, Elem x, int tipo){
	No *new = (No *) malloc(sizeof(No));
	if (new != NULL){
		new->tipo = tipo;
		switch (tipo){
			case t_int:
				new->info.atom.i = x.atom.i;
				break;

			case t_float:
				new->info.atom.f = x.atom.f;
				break;

			case t_char:
				new->info.atom.c = x.atom.c;
				break;

			case t_string:
				new->info.atom.s = x.atom.s;
				break;

			case t_sublist:
				new->info.sub = x.sub;
				break;
		}
		
		if (L->ini == NULL)
			L->ini = new;
		else 
			L->fim->prox = new;
		L->fim = new;
		new->prox = NULL;
	}
}

void append(ListaGen* child, ListaGen* parent){
	No *new = (No *) malloc(sizeof(No));
	if (new != NULL){
		new->tipo = t_sublist;
		new->info.sub = child->ini;
		push(parent, new->info, t_sublist);
	}
}

int rec_busca(No *u, Elem x, int tipo){
	if (u == NULL) return 0;
	if (u->tipo != t_sublist && u->tipo == tipo){
		printf("%c -> ", u->info.atom.c);
		switch (tipo){
			case t_int:
				if (u->info.atom.i == x.atom.i) return 1;
				break;

			case t_float:
				if (u->info.atom.f == x.atom.f) return 1;
				break;

			case t_char:
				if (u->info.atom.c == x.atom.c) return 1;
				break;

			case t_string:
				if (u->info.atom.s == x.atom.s) return 1;
				break;
		}
	} else if (u->tipo == t_sublist){
		if (rec_busca(u->info.sub, x, tipo)) return 1;
	}
	return rec_busca(u->prox, x, tipo);
}

int busca(ListaGen *L, Elem x, int tipo){
	return rec_busca(L->ini, x, tipo);
}

int max(int a, int b){
	return a > b ? a : b;
}

int rec_profun(No *u){
	if (u == NULL) return 0;
	int cauda = rec_profun(u->prox);
	if (u->tipo == t_sublist) return max(1+rec_profun(u->info.sub), cauda);
	return max(1, cauda);
}

int profundidade(ListaGen* L){
	return rec_profun(L->ini);
}
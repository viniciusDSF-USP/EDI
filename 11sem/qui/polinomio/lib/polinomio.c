#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"
#include <math.h>

Pol *criar(){
	Pol *P = (Pol *) malloc(sizeof(Pol));
	if (P != NULL){
		P->ini = NULL;
		P->fim = NULL;
	}
	return P;
}

void criarTermo(Pol *P, int val){
	No *new = (No *) malloc(sizeof(No));
	if (new != NULL){
		new->var.sub = NULL;
		new->tipo = t_sub;
		new->val = val;
		
		if (P->ini == NULL) P->ini = new;
		else P->fim->prox = new;
		P->fim = new;
		new->prox = NULL;
	}
}

void removerTermo(Pol *P){
	if (P->fim == NULL) return;
	
	No *aux, *p;
	
	p = P->fim->var.sub;
	while (p != NULL){
		aux = p->prox;
		free(p);
		p = aux;
	}
	
	p = P->ini;
	if (p == P->fim){
		free(p);
		P->ini = NULL;
		P->fim = NULL;
	} else {
		while (p != NULL && p->prox != P->fim){
			p = p->prox;
		}
		p->prox = NULL;
		
		free(P->fim);
		P->fim = p;
	}
}

void pushVar(Pol *P, char sym, int pot){
	No *p;
	
	p = P->fim->var.sub;
	while (p != NULL && p->prox != NULL){
		p = p->prox;
	}
	
	No *new = (No *) malloc(sizeof(No));
	if (new != NULL){
		new->var.sym = sym;
		new->tipo = t_sym;
		new->val = pot;
		
		if (p == NULL) P->fim->var.sub = new;
		else p->prox = new;
		new->prox = NULL;
	}
}

void popVar(Pol *P, char sym){
	if (P->fim == NULL) return;
	
	No *aux, *p;
	aux = P->fim->var.sub;
	
	p = aux;
	while (p != NULL){
		if (p->var.sym == sym){
			if (aux == p) P->fim->var.sub = p->prox;
			else aux->prox = p->prox;
			free(p);
			break;
		}
		aux = p;
		p = p->prox;
	}
}

int abs(int a){
	return a >= 0 ? a : -a;
}

void printPol(Pol *P){
	if (P->ini == NULL) {
		printf("\n");
		return;
	}
	
	No *i, *p;
	
	printf("%d", P->ini->val);
	
	p = P->ini->var.sub;
	while (p != NULL){
		printf("%c", p->var.sym);
		if (p->val != 1) printf("^{%d}", p->val);
		p = p->prox;
	}
	
	i = P->ini->prox;
	while (i != NULL){
		if (i->val < 0) printf(" - ");
		else printf(" + ");
		
		printf("%d", abs(i->val));
		
		p = i->var.sub;
		while (p != NULL){
			printf("%c", p->var.sym);
			if (p->val != 1) printf("^{%d}", p->val);
			p = p->prox;
		}
		
		i = i->prox;
	}
	
	printf("\n");
}

// Parte pra calcular valor do polinomio em x,y,...,z

Dict *criarDict(){
	Dict *D = (Dict *) malloc(sizeof(Dict));
	if (D != NULL){
		D->topo = NULL;
	}
	return D;
}

void pushDict(Dict *D, char var, int val){
	NoDict *new = (NoDict *) malloc(sizeof(NoDict));
	if (new != NULL){
		new->var = var;
		new->val = val;
	
		new->prox = D->topo;
		D->topo = new;
	}
}

void popDict(Dict *D, NoDict *out){
	if (D->topo != NULL){
		NoDict *aux;
		
		out->var = D->topo->var;
		out->val = D->topo->val;
		
		aux = D->topo;
		D->topo = D->topo->prox;
		free(aux);
	}
}

int eval(Pol *P, Dict *D){
	No *i, *j;
	NoDict d;
	
	while (D->topo != NULL){
		popDict(D, &d);
		
		i = P->ini;
		while (i != NULL){
			j = i->var.sub;

			while (j != NULL){
				if (j->var.sym == d.var)
					j->val = pow(d.val, j->val);
				j = j->prox;
			}
			
			i = i->prox;
		}
	}
	
	int ans=0;
	i = P->ini;
	while (i != NULL){
		j = i->var.sub;
		
		while (j != NULL){
			i->val *= j->val;
			j = j->prox;
		}
		ans += i->val;
		
		i = i->prox;
	}
	
	return ans;
}
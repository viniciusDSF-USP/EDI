#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

Pol *create(){
	Pol *P = (Pol *) malloc(sizeof(Pol));
	
	if (P != NULL){
		P->ini = P->fim = NULL;
	}
	
	return P;
}

void pushTermo(Pol *P, int val){
	if (val == 0) return;
	
	No *new = (No *) malloc(sizeof(No));
	
	if (new != NULL){
		new->val = val;
		new->var.sub = NULL;
		new->prox = NULL;
		
		if (P->ini == NULL) P->ini = new;
		else P->fim->prox = new;
		P->fim = new;
	}
}

void pushVar(Pol *P, char var, int exp){
	if (exp == 0) return;
	
	No *new = (No *) malloc(sizeof(No));
	
	if (new != NULL){
		new->var.sym = var;
		new->val = exp;
		new->prox = NULL;
		
		No *p = P->fim->var.sub;
		
		if (p == NULL) P->fim->var.sub = new;
		else {
			while (p->prox != NULL){
				p = p->prox;
			}
			p->prox = new;
		}
	}
}

int abs(int x){
	return x > 0 ? x : -x;
}

void print(Pol *P){
	No *p = P->ini, *pj;
	
	if (p != NULL){
		if (p->val < 0) printf("-");
		if (abs(p->val) != 1) printf("%d", abs(p->val));
		
		pj = p->var.sub;
		while (pj != NULL){
			printf("%c", pj->var.sym);
			if (pj->val != 1) printf("^{%d}", pj->val);
		
			pj = pj->prox;
		}
		
		p = p->prox;
		
		while (p != NULL){
			printf(" %c ", p->val < 0 ? '-' : '+');
			if (abs(p->val) != 1) printf("%d", abs(p->val));
			
			pj = p->var.sub;
			while (pj != NULL){
				printf("%c", pj->var.sym);
				if (pj->val != 1) printf("^{%d}", pj->val);
			
				pj = pj->prox;
			}
			
			p = p->prox;
		}
		
		printf("\n");
	}
}

void add(Dict *D, char var, int val){
	NoDict *d = D->ini, *aux;
	
	while (d != NULL){
		if (d->var == var){
			d->val = val;
			return;
		}
		
		aux = d;
		d = d->prox;
	}
	
	NoDict *new = (NoDict *) malloc(sizeof(NoDict));
	
	if (new != NULL){
		new->var = var;
		new->val = val;
		new->prox = NULL;
		
		if (D->ini == NULL) D->ini = new;
		else aux->prox = new;
	}
}

Dict *createDict(Pol *P){
	Dict *D = (Dict *) malloc(sizeof(Dict));
	
	if (D != NULL){
		D->ini = NULL;
		
		No *p = P->ini, *pj;
		
		while (p != NULL){
			pj = p->var.sub;
			while (pj != NULL){
				add(D, pj->var.sym, 0);
				
				pj = pj->prox;
			}
			
			p = p->prox;
		}
	}
	
	return D;
}

void printDict(Dict *D, char op){
	NoDict *d = D->ini;
	
	while (d != NULL){
		if (op == 'K') printf("%c", d->var);
		else printf("%d", d->val);
		
		if (d->prox != NULL) printf(",");
		d = d->prox;
	}
}

int eval(Pol *P, Dict *D){
	No *p, *pj;
	NoDict *d;
	
	int somaGlo = 0, somaLoc;
	
	p = P->ini;
	while (p != NULL){
		somaLoc = p->val;
		
		pj = p->var.sub;
		while (pj != NULL){
			d = D->ini;
			while (d != NULL){
				if (d->var == pj->var.sym){
					somaLoc *= pow(d->val, pj->val);
					break;
				}
				
				d = d->prox;
			}
			
			pj = pj->prox;
		}
		
		somaGlo += somaLoc;
		
		p = p->prox;
	}
	
	return somaGlo;
}
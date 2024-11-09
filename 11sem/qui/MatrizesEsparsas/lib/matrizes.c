#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

Matriz *criar(int lin, int col){
	Matriz *M = (Matriz *) malloc(sizeof(Matriz));
	
	if (M != NULL){
		No *new;
		No *p;
		
		new = (No *) malloc(sizeof(No));
			
		if (new != NULL){
			new->lin = 0;
			new->col = 0;
			
			M->ini = new;
			new->proxlin = M->ini;
			new->proxcol = M->ini;
		} else {
			return NULL;
		}
		
		p = M->ini;
		for (int i=1; i<=lin; i++){
			new = (No *) malloc(sizeof(No));
			
			if (new != NULL){
				new->lin = i;
				new->col = 0;
				
				new->proxlin = M->ini;
				new->proxcol = new;
				
				p->proxlin = new;
				p = new;
			} else {
				exit(0);
			}
		}
		
		p = M->ini;
		for (int j=1; j<=col; j++){
			new = (No *) malloc(sizeof(No));
			
			if (new != NULL){
				new->lin = 0;
				new->col = j;
				
				new->proxcol = M->ini;
				new->proxlin = new;
				
				p->proxcol = new;
				p = new;
			} else {
				exit(0);
			}
		}
		
		M->lin = lin;
		M->col = col;
	}
	
	return M;
}

No *col_lowerBusca(Matriz *M, int lin, int col){ // linha fixa, procura menor coluna
	No *pi = M->ini->proxlin;
	
	while (pi->lin != 0 && pi->lin != lin){
		pi = pi->proxlin;
	}
	
	if (pi->lin == 0) return NULL;
	
	No *pj = pi->proxcol;
	No *find = pi;
	
	while (pj->col != 0 && pj->col <= col){
		find = pj;
		
		pj = pj->proxcol;
	}
	
	return find;
}

No *lin_lowerBusca(Matriz *M, int lin, int col){ // coluna fixa, procura menor linha
	No *pi = M->ini->proxcol;
	
	while (pi->col != 0 && pi->col != col){
		pi = pi->proxcol;
	}
	
	if (pi->col == 0) return NULL;
	
	No *pj = pi->proxlin;
	No *find = pi;
	
	while (pj->lin != 0 && pj->lin <= lin){
		find = pj;
		
		pj = pj->proxlin;
	}
	
	return find;
}

void push(Matriz *M, int lin, int col, int x){
	if (x == 0) return;
	
	No *pc = col_lowerBusca(M, lin, col);
	No *pl = lin_lowerBusca(M, lin, col);
	
	if (pc != NULL && pl != NULL){
		if (pc->col < col){
			No *new = (No *) malloc(sizeof(No));
			
			if (new != NULL){
				new->lin = lin;
				new->col = col;
				new->val = x;
				
				new->proxcol = pc->proxcol;
				new->proxlin = pl->proxlin;
				
				pc->proxcol = new;
				pl->proxlin = new;
			}
		} else { // pc->col == col, entao ja existe esse elemento
			pc->val = x;
		}
	}
}

void print(Matriz *M){
	No *pi, *pj;
	
	pi = M->ini->proxlin;
	while (pi->lin != 0){
		pj = pi->proxcol;
		while (pj->col != 0){
			printf("%4d", pj->val);
			
			pj = pj->proxcol;
			if (pj->col == 0) printf("\n");
			else printf(" ");
		}
		
		pi = pi->proxlin;
	}
}

void printZ(Matriz *M){
	No *pi, *pj;
	int j;
	
	pi = M->ini->proxlin;
	while (pi->lin != 0){
		pj = pi->proxcol;
		j = 1;
		
		while (pj->col != 0){
			while (j < pj->col){
				printf("%4d", 0);
				printf(" ");
				j++;
			}
			j++;
			
			printf("%4d", pj->val);
			
			pj = pj->proxcol;
			if (pj->col == 0 && j >= M->col) printf("\n");
			else printf(" ");
		}
		
		while (j <= M->col){
			printf("%4d", 0);
			if (j == M->col) printf("\n");
			else printf(" ");
			j++;
		}
		
		pi = pi->proxlin;
	}
}

int soma(Matriz *M){
	No *pi, *pj;
	
	int sum = 0;
	
	pi = M->ini->proxlin;
	while (pi->lin != 0){
		pj = pi->proxcol;
		while (pj->col != 0){
			sum += pj->val;
			
			pj = pj->proxcol;
		}
		
		pi = pi->proxlin;
	}
	
	return sum;
}

void pop(Matriz *M, No *p){
	No *antcol = col_lowerBusca(M, p->lin, p->col-1);
	No *antlin = lin_lowerBusca(M, p->lin-1, p->col);
	
	if (antlin != NULL)
		antlin->proxlin = p->proxlin;
	if (antcol != NULL)
		antcol->proxcol = p->proxcol;
	
	free(p);
}

void add(Matriz *M, int lin, int col, int k){
	if (k == 0) return;
	
	No *pi;
	
	if (lin == 0){ // somar k em col
		pi = lin_lowerBusca(M, lin, col);
		
		if (pi != NULL){
			int i = 1;
			pi = pi->proxlin;
			
			while (pi->lin != 0){
				while (i < pi->lin){ // Tinha zero antes nessa coluna, mas agora vai somar k
					push(M, i, col, k);
					i++;
				}
				i++;
				
				pi->val += k;
				
				if (pi->val == 0){
					pop(M, pi);
				}
			
				pi = pi->proxlin;
			}
			
			while (i <= M->lin){ // Tinha zero antes nessa coluna, mas agora vai somar k
				push(M, i, col, k);
				i++;
			}
		}
	} else if (col == 0){ // somar k em lin
		pi = col_lowerBusca(M, lin, col);
		
		if (pi != NULL){
			int j = 1;
			pi = pi->proxcol;
			
			while (pi->col != 0){
				while (j < pi->col){ // Tinha zero antes nessa linha, mas agora vai somar k
					push(M, lin, j, k);
					j++;
				}
				j++;
				
				pi->val += k;
				
				if (pi->val == 0){
					pop(M, pi);
				}
			
				pi = pi->proxcol;
			}
			
			while (j <= M->col){ // Tinha zero antes nessa linha, mas agora vai somar k
				push(M, lin, j, k);
				j++;
			}
		}
	} else { // somar k em (lin,col)
		pi = col_lowerBusca(M, lin, col);
		
		if (pi->col < col){ // (lin,col) nao existe
			return;
		} else {
			pi->val += k;
			
			if (pi->val == 0){
				pop(M, pi);
			}
		}
	}
}
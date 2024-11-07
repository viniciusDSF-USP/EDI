#include <stdio.h>
#include <stdlib.h>
#include "bignum.h"

int _len(char *s){
	int len = 0;
	while (s != NULL && *s != '\0'){
		len++;
		s++;
	}
	return len;
}

Big *criar(char *num){
	Big *B = (Big *) malloc(sizeof(Big));
	
	if (B != NULL){
		No *p;
		No *new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = -1;
			new->prox = new;
			B->ini = new;
		
			int n = _len(num);
			p = B->ini;
		
			while (n > 0){
				new = (No *) malloc(sizeof(No));
				
				if (new != NULL){
					new->info = num[--n]-'0';
					new->prox = B->ini;
					
					p->prox = new;
					p = new;
				} else {
					exit(0);
				}
			}
		} else {
			exit(0);
		}
	}
	
	return B;
}

Big *somar(Big *num1, Big *num2){
	Big *soma = criar(NULL);
	
	No *p1 = num1->ini->prox;
	No *p2 = num2->ini->prox;
	No *p3 = soma->ini->prox;
	No *new;
	int resto = 0;
	
	while (p1->info != -1 && p2->info != -1){ // Enquanto num1 e num2 tiverem msm tamanho
		new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = p1->info+p2->info+resto;
			new->prox = soma->ini;
			
			if (new->info >= 10) {
				resto = (new->info)/10;
				new->info %= 10;
			} else {
				resto = 0;
			}
			
			p3->prox = new;
			p3 = new;
		} else {
			exit(0);
		}
		
		p1 = p1->prox;
		p2 = p2->prox;
	}
	
	while (p1->info != -1){ // Enquanto tiver num1
		new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = p1->info+resto;
			new->prox = soma->ini;
			
			if (new->info >= 10) {
				resto = (new->info)/10;
				new->info %= 10;
			} else {
				resto = 0;
			}
			
			p3->prox = new;
			p3 = new;
		} else {
			exit(0);
		}
		
		p1 = p1->prox;
	}
	
	while (p2->info != -1) { // Enquanto tiver num2
		new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = p2->info+resto;
			new->prox = soma->ini;
			
			if (new->info >= 10) {
				resto = (new->info)/10;
				new->info %= 10;
			} else {
				resto = 0;
			}
			
			p3->prox = new;
			p3 = new;
		} else {
			exit(0);
		}
		
		p2 = p2->prox;
	}
	
	if (resto){ // Se tiver resto
		new = (No *) malloc(sizeof(No));
		
		if (new != NULL){
			new->info = resto;
			new->prox = soma->ini;
			
			if (new->info >= 10) {
				resto = (new->info)/10;
				new->info %= 10;
			} else {
				resto = 0;
			}
			
			p3->prox = new;
			p3 = new;
		} else {
			exit(0);
		}
	}

	return soma;
}

void RecBP(No *c){
	if (c->info != -1) {
		RecBP(c->prox);
		printf("%d", c->info);
	}
}

void BigPrint(Big *num){
	RecBP(num->ini->prox);
}
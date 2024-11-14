#include <stdio.h>
#include <stdlib.h>

#define FORMAT "%d"
typedef int elem;

typedef struct bloco {
	elem info;
	struct bloco *prox;
} No;

typedef struct {
	No *ini, *fim;
} Lista;

Lista *criar();
int inserir(Lista *L, elem x);
void print(char *pre, Lista *L, char *pos);
char *iguais_ite(Lista *L1, Lista *L2);
char *iguais_rec(No *p1, No *p2);

int main(){
	Lista *L1, *L2;
	
	L1 = criar();
	L2 = criar();
	
	print("L1 = [", L1, "], ");
	print("L2 = [", L2, "]\n");
	
	printf("(Iterativo) L1 == L2: %s\n", iguais_ite(L1, L2));
	printf("(Recursivo) L1 == L2: %s\n\n", iguais_rec(L1->ini, L2->ini));
	
	inserir(L1, 2);
	inserir(L1, 3);
	
	inserir(L2, 2);
	inserir(L2, 3);
	
	print("L1 = [", L1, "], ");
	print("L2 = [", L2, "]\n");
	
	printf("(Iterativo) L1 == L2: %s\n", iguais_ite(L1, L2));
	printf("(Recursivo) L1 == L2: %s\n\n", iguais_rec(L1->ini, L2->ini));
	
	inserir(L2, 4);
	
	print("L1 = [", L1, "], ");
	print("L2 = [", L2, "]\n");
	
	printf("(Iterativo) L1 == L2: %s\n", iguais_ite(L1, L2));
	printf("(Recursivo) L1 == L2: %s\n\n", iguais_rec(L1->ini, L2->ini));
	
	inserir(L1, 4);
	
	print("L1 = [", L1, "], ");
	print("L2 = [", L2, "]\n");
	
	printf("(Iterativo) L1 == L2: %s\n", iguais_ite(L1, L2));
	printf("(Recursivo) L1 == L2: %s\n", iguais_rec(L1->ini, L2->ini));

	return 0;
}

Lista *criar(){
	Lista *L = (Lista *) malloc(sizeof(Lista));
	
	if (L != NULL) L->ini = L->fim = NULL;
	
	return L;
}

int inserir(Lista *L, elem x){
	No *new = (No *) malloc(sizeof(No));
	
	if (new == NULL) return 0;
	
	new->info = x;
	new->prox = NULL;
	
	if (L->ini == NULL) L->ini = new;
	else L->fim->prox = new;
	L->fim = new;
}

void print(char *pre, Lista *L, char *pos){
	printf("%s", pre);
	
	No *p = L->ini;
	while (p != NULL){
		printf(FORMAT, p->info);
	
		if (p->prox != NULL) printf(", ");
		p = p->prox;
	}
	
	printf("%s", pos);
}

char *iguais_ite(Lista *L1, Lista *L2){
	No *p1, *p2;
	
	p1 = L1->ini;
	p2 = L2->ini;
	
	while (p1 != NULL && p2 != NULL){
		if (p1->info != p2->info) return "False";
		
		p1 = p1->prox;
		p2 = p2->prox;
	}
	
	if (p1 != NULL || p2 != NULL) return "False";
	return "True";
}

char *iguais_rec(No *p1, No *p2){
	if (p1 == NULL && p2 == NULL) return "True";
	if (p1 == NULL || p2 == NULL) return "False";
	if (p1->info != p2->info) return "False";
	
	return iguais_rec(p1->prox, p2->prox);
}
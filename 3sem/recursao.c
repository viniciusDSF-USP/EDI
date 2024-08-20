// 3sem - ED I
#include <stdio.h>
#include <stdlib.h>

void printRec(int* v, int n);
void printRec2(int* v, int n);
int sumRec(int *v, int n, int k);
int minRec(int *v, int n, int m);
int maxRec(int *v, int n, int m);

const int ninf = 0x80000001; // -MAX_INT
const int inf = 0x7FFFFFFF; // +MAX_INT

typedef struct _pessoa{
	char nome[50];
	int idade;
	struct _pessoa* prox;
} pessoa;

void printRecStruct(pessoa* u);

int main(int argc, char* argv[]){
	if (argc == 1) {
		printf("./ (1) para vetor com recursao\n./ (2) para struct.\n");
		return 0;
	}

	switch(argv[1][0]){
		case '1':
			int n;

			printf("Tamanho: ");
			scanf("%d", &n);

			int* v = (int*) malloc(n * sizeof(int));
			for (int i=0; i<n; i++){
				printf("%d-esimo inteiro: ", i+1);
				scanf("%d", &v[i]);
			}

			printRec(v, n);
			printf("sum: %d\n", sumRec(v, n, 0));
			printf("min: %d\n", minRec(v, n, inf));
			printf("max: %d\n", maxRec(v, n, ninf));
			break;

		case '2':
			pessoa root;

			printf("Nome (digite 0 0 para finalizar): ");
			fgets(root.nome, 50, stdin);

			printf("Idade: ");
			scanf("%d", &root.idade);

			pessoa* old;
			old = &root;

			while (1) {
				pessoa* x = (pessoa*) malloc(sizeof(pessoa));

				getchar();

				printf("Nome: ");
				fgets(x->nome, 50, stdin);

				printf("Idade: ");
				scanf("%d", &x->idade);

				if (x->nome[0] == '0' && x->idade == 0) break;

				old->prox = x;
				old = x;
			}

			printRecStruct(&root);

			break;
	}

	return 0;
}

// Funcoes

void printRecStruct(pessoa* u){
	printf("(%s, %d)", u->nome, u->idade);

	if (u->prox == NULL) {
		printf("\n");
		return;
	}

	printf(" -> ");

	printRecStruct(u->prox);
	return;
}

void printRec(int *v, int n){
	printf("\n[");

	printRec2(v, n);

	printf("]\n");

	return;
}

void printRec2(int *v, int n){
	printf("%d", *v);

	if (n == 1) return;

	printf(", ");
	printRec2(&v[1], n-1);

	return;
}

int sumRec(int* v, int n, int k){
	if (n == 0) return k;
	return sumRec(&v[1], n-1, *v+k);
}

int minRec(int* v, int n, int m){
	if (n == 0) return m;
	if (*v < m) return minRec(&v[1], n-1, *v);
	else return minRec(&v[1], n-1, m);
}

int maxRec(int* v, int n, int m){
	if (n == 0) return m;
	if (*v > m) return maxRec(&v[1], n-1, *v);
	else return maxRec(&v[1], n-1, m);
}

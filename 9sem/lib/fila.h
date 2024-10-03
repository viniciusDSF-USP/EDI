#define TAM 5
#define var char

typedef struct {
	var info;
	int prox;
} no;

typedef struct {
	no itens[TAM];
	int ini, fim, vazio;
} Fila;

void create(Fila *v);
void push(Fila *v, var x, int *err);
void pop(Fila *v, var *x, int *err);
void clear(Fila *v);
int empty(Fila *v);
int full(Fila *v);
int print(Fila v);
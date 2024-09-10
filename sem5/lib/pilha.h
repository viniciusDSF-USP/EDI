#define TAM 10
#define type int

typedef struct {
	type itens[TAM];
	int topo;
} stack;

stack *Create(int *);
void check(int *);
int Empty(stack *);
int Full(stack *);
void Push(stack *, type, int *);
type Top(stack *, int *);
void Pop(stack *, int *);

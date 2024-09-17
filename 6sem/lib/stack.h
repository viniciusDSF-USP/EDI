#define TAM 30
typedef int type;

typedef struct {
	type itens[TAM];
	int topo;
} stack;

void stackCreate(stack *);
int stackEmpty(stack *);
int stackFull(stack *);
void stackPush(stack *, int, int *);
void stackPop(stack *, int *, int *);

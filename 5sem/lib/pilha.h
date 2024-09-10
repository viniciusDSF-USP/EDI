#define TAM 10
#define type char*
#define subtype char
#define varempty '\0'

typedef struct {
	type itens[TAM];
	int topo;
} stack;

stack *Create(int *);
void alloc(stack *, int *);
void check(int *);
int Empty(stack *);
int Full(stack *);
void Push(stack *, type, int *);
void SubPush(stack *, subtype, int *);
type Top(stack *, int *);
void Pop(stack *, int *);
int Size(stack *);

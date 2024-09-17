#define TAM 30
typedef int type;

typedef struct {
	int ini, fim, total, itens[TAM];
} queue;

void Create(queue *);
void Clear(queue *);
int Empty(queue *);
int Full(queue *);
void Push(queue *, int, int *);
void Front(queue *, int *, int *);

#define TAM 30

union var {
        int i;
        char c;
        float f;
        double d;
};

typedef struct {
	union var v;
        int type; // i: 0, c: 1, f: 2, d: 3
} var;

typedef struct {
	int ini, fim, total;
	var itens[TAM];
} queue;

void Create(queue *);
void Clear(queue *);
int Empty(queue *);
int Full(queue *);
void Push(queue *, var, int *);
void Front(queue *, var *, int *);

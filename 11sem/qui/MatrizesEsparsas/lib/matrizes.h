typedef struct bloco {
	int lin, col, val;
	struct bloco *proxlin, *proxcol;
} No;

typedef struct {
	No *ini;
	int lin, col;
} Matriz;

Matriz *criar(int, int);
void push(Matriz *, int, int, int);
void print(Matriz *);
void printZ(Matriz *);
int soma(Matriz *);
void add(Matriz *, int, int, int);
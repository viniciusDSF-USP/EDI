typedef int elem;

typedef struct bloco {
    elem info;
    int lin, col;

    struct bloco *proxlin, *proxcol;
} No;

typedef struct {
    No *head;
    int lin, col;
} Matriz;

Matriz *criar(int lin, int col);
int inserir(Matriz *M, int lin, int col, elem x);
int remover(Matriz *M, int lin, int col);
void print(Matriz *M);
int somar_linha(Matriz *M, int lin, elem x);
int somar_coluna(Matriz *M, int col, elem x);
#define S 10
typedef int elem;

typedef struct bloco {
	elem info;
	int FB, altura;
	struct bloco *esq, *dir;
} No;

typedef struct {
	No *raiz;
} AVL;

AVL *criar();
int inserir(No **p, elem x);
int remover(No **p, elem x);
void print(char *pre, No *p, char *pos);
#define FORMAT %d
typedef int elem;

typedef struct bloco {
	elem info;
	int FB;
	struct bloco *esq, *dir;
} No;

typedef struct {
	No *raiz;
} AVL;

AVL *criar();
void inserir(AVL *A, elem x);
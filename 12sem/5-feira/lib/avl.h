#define LINE 8
#define FORMAT "%d"
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
int inserir(AVL *A, elem x);
void print(char *pre, AVL *A, char *pos);
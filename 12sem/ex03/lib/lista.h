#define FORMAT "%d"
typedef int elem;

typedef struct bloco {
	elem info;
	struct bloco *esq, *dir;
} No;

typedef struct {
	No *ini;
} Lista;

Lista *cria();
int esta_vazia(Lista *L);
int esta_na_lista(Lista *L, elem x);
int insere_a_direita_de(Lista *L, elem x, elem y);
void print(char *pre, Lista *L, char *pos);
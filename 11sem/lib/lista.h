typedef struct no No;

typedef union {
	int i;
	float f;
	char c;
	char *s;
} Atom;

typedef union {
	Atom atom;
	No* sub;
} Elem;

struct no {
	Elem info;
	enum {t_int, t_float, t_char, t_string, t_sublist} tipo;
	struct no *prox;
};

typedef struct {
	No *ini;
} ListaGen;

No *criarNo(Elem, int);
int busca(ListaGen*, Elem, int);
int iguais(ListaGen*, ListaGen*);
int profundidade(ListaGen*);
typedef struct no {
	union Elem {
		char sym;
		struct no* sub;
	} var;
	enum {t_sym, t_sub} tipo;
	int val;
	
	struct no *prox;
} No;

typedef struct {
	No *ini;
	No *fim;
} Pol;

typedef struct nodict {
	char var;
	int val;
	struct nodict* prox;
} NoDict;

typedef struct {
	NoDict *topo;
} Dict;

Pol *criar();
void criarTermo(Pol *, int);
void removerTermo(Pol *);
void pushVar(Pol *, char, int);
void popVar(Pol *, char);
void printPol(Pol *);

Dict *criarDict();
void pushDict(Dict *, char, int);
void popDict(Dict *, NoDict *);
int eval(Pol *, Dict *);
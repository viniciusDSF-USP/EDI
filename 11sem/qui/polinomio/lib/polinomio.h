typedef struct node {
	int val;
	union {
		char sym;
		struct node *sub;
	} var;
	
	struct node *prox;
} No;

typedef struct {
	No *ini, *fim;
} Pol;

Pol *create();
void pushTermo(Pol *, int);
void pushVar(Pol *, char, int);
void print(Pol *);

typedef struct nodedict {
	char var;
	int val;
	struct nodedict *prox;
} NoDict;

typedef struct {
	NoDict *ini;
} Dict;

Dict *createDict(Pol *);
void add(Dict *, char, int);
void printDict(Dict *, char);
int eval(Pol *, Dict *);
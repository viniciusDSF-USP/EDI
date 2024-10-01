typedef struct node node;
typedef struct amigos Amigos;
typedef struct filho Filho;
typedef struct pai Pai;
typedef struct lista Lista;

struct node {
	Filho *dados;
	node *prox;
};

struct amigos {
	node *ini, *fim;
};

struct pai {
	long long int cpf;
	char nome[50];
	Filho *filhos;
	Pai *prox;
};

struct filho {
	char nome[50];
	Filho *prox;
	Amigos *amigos;
};

struct lista {
	Pai *ini, *fim;
};

void Create(Lista *);
int AddPai(Lista *, long long int, char[]);
Pai *FindPai(Lista *, long long int);
void printL(Lista *);
#define TAB 30
#define STRLIM 100

typedef struct bloco_lista {
	char *nome;
	struct bloco_lista *prox;
} No_Lista;

typedef struct {
	No_Lista *ini;
} Lista;


typedef struct bloco_aluno {
	char *nome;
	int nroUSP;
	Lista *filmes_pred;
	
	int altura, FB;
	struct bloco_aluno *esq, *dir;
} No_Aluno;

typedef struct {
	No_Aluno *raiz;
} Aluno;

Aluno *criar_Aluno();
int inserir_aluno(No_Aluno **a, char *nome, int nroUSP);
No_Aluno **buscar_aluno(No_Aluno **a, int nroUSP);
void limpar_Aluno(No_Aluno **a);
void print_arvore(char *pre, No_Aluno *a, char *pos);
void print_aluno(char *pre, No_Aluno **a, int nroUSP, char *pos);

int inserir_filme(No_Aluno **a, int nroUSP, char *nome);
int remover_filme(No_Aluno **a, int nroUSP, char *nome);
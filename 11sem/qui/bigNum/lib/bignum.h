typedef struct bloco {
	int info;
	struct bloco *prox;
} No;

typedef struct {
	No *ini;
} Big;

Big *criar(char *);
Big *somar(Big *, Big *);
void BigPrint(Big *);
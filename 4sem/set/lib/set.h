
typedef struct _set set;

set *Criar_conjunto(int n);

int Inserir(int x, set *A);

int Remover(int x, set *A);

void Imprimir(set *A);

int Membro(int x, set *A);

int Min(set *A);

int Max(set *A);

void Liberar(set *A);

int Igual(set *A, set *B);

void Atribuir(set *A, set *B);

void Uniao(set *A, set *B, set *C);

void Interseccao(set *A, set *B, set *C);

void Diferenca(set *A, set *B, set *C);

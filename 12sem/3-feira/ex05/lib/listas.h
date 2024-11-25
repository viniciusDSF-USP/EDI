typedef enum {Real, Int, Char, Sub} type;

typedef union {
    float f;
    int i;
    char c;
} atomo;

typedef struct {
    union {
        atomo atom;
        struct bloco_listagen *sub;
    } info;
    type tipo;
} elem;

typedef struct bloco_listagen{
    union {
        atomo atom;
        struct bloco_listagen *sub;
    } info;
    type tipo;

    struct bloco_listagen *prox;
} NoGen;

typedef struct bloco_listadup{
    atomo info;
    type tipo;

    struct bloco_listadup *esq;
    struct bloco_listadup *dir;
} NoDup;

typedef struct {
    NoGen *ini;
} ListaGen;

typedef struct {
    NoDup *ini;
} ListaDup;

ListaGen *ListaGen_criar();
ListaDup *ListaDup_criar();
int ListaGen_inserir(NoGen **L, elem *x, char prof);
void ListaGen_print(ListaGen *L);
void Limpar(NoDup **D);
int Converter(NoGen **L, NoDup **D);
void ListaDup_print(ListaDup *D);
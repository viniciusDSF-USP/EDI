typedef struct no {
	int info;
	struct no *prox;
} no;

typedef struct vector {
	no *ini;
	no *fim;
} vector;

vector *vecCreate(vector *, int *);
void vecPush_back(vector *, int, int *);
void vecDelete(vector *, int, int *);
no *vecFind(vector *, int, int *);
int vecLen(vector *);
void vecClear(vector *);
void vecPrint(vector *);
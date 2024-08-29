#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct _set {
    int *set;
    int length;
    int end;
};

const int ninf = 0x80000001;
set *Criar_conjunto(int n){
	n = (n == 0) ? 0 : n-1;

	set *A = (set *) malloc(sizeof(set));
	A->set = (int *) malloc(n * sizeof(int));
	A->length = n;
	A->end = 0;

	for (int i=0; i<A->length; i++) A->set[i] = ninf;

	return A;
}

int __lower_bound(int x, set *A){
	int ans = -1;

	int l=0, r=A->end-1, mid;
	while (l <= r){
		mid = l + (r-l)/2;

		if (A->set[mid] <= x){
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}

	return ans;
}

int Inserir(int x, set *A){
	int j = __lower_bound(x, A);
	if (j > -1 && A->set[j] == x){
		return 0; // Repetido
	} else {
		if (A->end <= A->length){
			if (A->set[j+1] != ninf)
				for (int i=A->end; i>j+1; i--) A->set[i] = A->set[i-1];
			A->set[j+1] = x;
			A->end++;
		} else {
			return -1; // Conjunto cheio
		}
	}

	return 1; // Inserido
}

int Remover(int x, set *A){
	int j = __lower_bound(x, A);
	if (j > -1 && A->set[j] == x){
		int i;
		for (i=j; i<A->end; i++){
			A->set[i] = A->set[i+1];
		}
		A->set[i] = ninf;
		A->end--;
	} else {
		return 0; // Nada a ser removido
	}

	return 1; // Removido
}

void Imprimir(set *A){
	printf("{");
	for (int i=0; i<A->end; i++){
		printf("%d", A->set[i]);
		if (i < A->end-1) printf(", ");
	}
	printf("}\n");
	return;
}

int Membro(int x, set *A){
	int j = __lower_bound(x, A);
	if (j == -1) return 0;
	if (A->set[j] != x) return 0;
	return 1;
}

int Min(set *A){
	return A->set[0];
}

int Max(set *A){
	return A->set[A->end-1];
}

void Liberar(set *A){
	free(A->set);
	free(A);
	return;
}

int Igual(set *A, set *B){
	if (A->end != B->end) return 0;
	for (int i=0; i<A->end; i++){
		if (A->set[i] != B->set[i]) return 0;
	}
	return 1;
}

void Atribuir(set *A, set *B){
	A->set = (int *) realloc(A->set, B->length * sizeof(set));

	for (int i=0; i<B->length; i++){
		A->set[i] = B->set[i];
	}
	A->length = B->length;
	A->end = B->end;

	return;
}

void Uniao(set *A, set *B, set *C){
	Liberar(A);
	A = Criar_conjunto(B->end + C->end);

	for (int i=0; i<B->end; i++) A->set[i] = B->set[i];
	A->end = B->end;

	for (int i=0; i<C->end; i++){
		Inserir(C->set[i], A);
	}

	return;
}

void Interseccao(set *A, set *B, set *C){
	if (B->end >= C->end) {
		Liberar(A);
		A = Criar_conjunto(B->end);

		for (int i=0, val; i<B->end; i++){
			val = B->set[i];
			if (Membro(val, B) == 1 && Membro(val, C) == 1)
				Inserir(val, A);
		}
	} else {
		Liberar(A);
		A = Criar_conjunto(C->end);

        for (int i=0, val; i<C->end; i++){
            val = C->set[i];
            if (Membro(val, B) == 1 && Membro(val, C) == 1)
            	Inserir(val, A);
        }
	}

	return;
}

void Diferenca(set *A, set *B, set *C){
	Atribuir(A, B);

    for (int i=0; i<B->end; i++){
    	Remover(C->set[i], A);
    }

    return;
}

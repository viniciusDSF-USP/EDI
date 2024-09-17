#include <stdio.h>
#include <stdlib.h>
#include "lib/biblio.h"

int main(){
	int err=0;
	Livro L = {1, "O Nome do Vento", 1};

	CadastraLivro(L, &err);

	for (int i=0; i<BOOKS; i++){
		L = Biblioteca.Livros[i];
		printf("%d. {%lld, %s, %d}\n", i, L.isbn, L.nome, L.disponivel);
	}

	return 0;
}

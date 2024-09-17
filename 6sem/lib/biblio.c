#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int LivroCadastrado(Livro L){
	int l=0, r=BOOKS-1;
	int mid;
	while (l <= r){
		mid = l+(r-l)/2;

		if (Biblioteca.Livros[mid].isbn < L.isbn){
			l = mid+1;
		} else if (Biblioteca.Livros[mid].isbn > L.isbn){
			r = mid-1;
		} else {
			return 1;
		}
	}
	return 0;
}

int PessoaCadastrada(Pessoa P){
	int l=0, r=QUEUE-1;
	int mid;
	while (l <= r){
		mid = l+(r-l)/2;

		if (Biblioteca.Usuarios[mid].cpf < P.cpf){
			l = mid+1;
		} else if (Biblioteca.Usuarios[mid].cpf > P.cpf){
			r = mid-1;
		} else {
			return 1;
		}
	}
	return 0;
}

int _lbLivros(int isbn){
	int l=0, r=BOOKS-1;
	int mid;
	int i=-1;
	while (l <= r){
		mid = l+(r-l)/2;

		if (Biblioteca.Livros[mid].isbn < L.isbn){
			l = mid+1;
			i = mid;
		} else {
			r = mid-1;
		}
	}
	return i+1;
}

void CadastraLivro(Livro L, int *err){
	if (LivroCadastrado(L)) *err = 1;
	else {
		int pos = _lbLivros(L.isbn);
		if (pos < qtdLivros){
			for (int i=BOOKS; i>pos; i--)
				Biblioteca.Livros[i] = Biblioteca.Livros[i-1];
		}
		Biblioteca.Livros[pos] = L;
		Biblioteca.qtdLivros++;
		*err = 0;
	}
	return;
}

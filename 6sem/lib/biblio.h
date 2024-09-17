#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE 100
#define BOOKS 100

typedef struct _Pessoa Pessoa;

typedef struct {
        int ini, fim, total;
        Pessoa itens[QUEUE];
} Queue;

typedef struct {
	long long int isbn;
        char nome[50];
        int disponivel;
        Queue filaEspera;
} Livro;

struct _Pessoa {
        long long int cpf;
        long long int numUSP;
        char nome[50];
        char endereco[100];

        Livro livros[3];
        int qtdLivros;
};

typedef struct {
	int qtdUsuarios;
	int qtdLivros;
	Pessoa Usuarios[QUEUE];
	Livro Livros[BOOKS];
} DB;

DB Biblioteca;
Biblioteca.qtdUsuarios = 0;
Biblioteca.qtdLivros = 0;
for (int i=0; i<QUEUE; i++) DB.Usuarios[i] = {0, 0};
for (int i=0; i<BOOKS; i++) DB.Livros[i] = {0};

int LivroCadastrado(Livro);
int PessoaCadastrada(Pessoa);

void CadastraLivro(Livro, int *);
void CadastraPessoa(Pessoa, int *);

void RetiraLivro(Pessoa, Livro, int *);
void DevolveLivro(Livro, int *);

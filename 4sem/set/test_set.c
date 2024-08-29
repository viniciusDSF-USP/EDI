#include <stdio.h>
#include <stdlib.h>
#include "lib/set.h"

int main(){
	set *ans = Criar_conjunto(0);
	set *A = Criar_conjunto(5);
	set *B = Criar_conjunto(7);

	char op, conj;
	int num;

	printf("==+== Operações com conjuntos ==+==\n");
	printf("[A] Adicionar (A, x);\n");
	printf("[R] Remover (A, x);\n");
	printf("[P] Imprimir (A);\n");
	printf("[m] Mínimo (A);\n");
	printf("[M] Máximo (A);\n");
	printf("[=] Iguais (-);\n");
	printf("[C] Membro (A,x);\n");
	printf("[U] União (-);\n");
	printf("[I] Intersecção (-);\n");
	printf("[D] Diferença (-);\n");
	printf("[qqq] Sair.\n\n");

	printf("(A, x): Conjunto e valor\n");
	printf("(A): Conjunto\n");
	printf("(-): Nenhum\n");

	while(1) {
		printf("Operação, conjunto e valor: ");
		scanf("%c %c %d", &op, &conj, &num);
		getchar();

		int err;
		switch (op) {
			case 'A':
				if (conj == 'A') err = Inserir(num, A);
				if (conj == 'B') err = Inserir(num, B);

				if (err == 0) printf("Erro: %d é repetido\n\n", num);
				else if (err == -1) printf("Erro: conjunto cheio\n\n");
				else {
					if (conj == 'A') printf("%d inserido no conjunto A\n\n", num);
					else if (conj == 'B') printf("%d inserido no conjunto B\n\n", num);
				}
				break;

			case 'R':
				if (conj == 'A') err = Remover(num, A);
				if (conj == 'B') err = Remover(num, B);

				if (err == 0) printf("%d não está no conjunto\n\n", num);
				else printf("%d removido\n\n", num);
				break;

			case 'P':
				if (conj == 'A') Imprimir(A);
				if (conj == 'B') Imprimir(B);
				break;

			case 'm':
				if (conj == 'A') printf("min(A) = %d\n\n", Min(A));
				if (conj == 'B') printf("min(B) = %d\n\n", Min(B));
				break;

			case 'M':
				if (conj == 'A') printf("max(A) = %d\n\n", Max(A));
				if (conj == 'B') printf("max(B) = %d\n\n", Max(B));
				break;

			case '=':
				printf("%c\n", (Igual(A, B) == 1) ? 'S' : 'N');
				break;

			case 'C':
				if (conj == 'A') printf("%c\n\n", (Membro(num, A) == 1) ? 'S' : 'N');
				if (conj == 'B') printf("%c\n\n", (Membro(num, B) == 1) ? 'S' : 'N');
				break;

			case 'U':
				printf("A ∪ B = ");
				Uniao(ans, A, B);
				Imprimir(ans);
				printf("\n");
				break;

			case 'I':
				printf("A ∩ B = ");
				Interseccao(ans, A, B);
				Imprimir(ans);
				printf("\n");
				break;

			case 'D':
				printf("A\\B = ");
				Diferenca(ans, A, B);
				Imprimir(ans);

				printf("B\\A = ");
                Diferenca(ans, B, A);
                Imprimir(ans);
				printf("\n");
                break;

			default:
				return 0;
		}
	}

	return 0;
}

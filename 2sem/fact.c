#include <stdio.h>
#include <stdlib.h>

const int MAX = 1e4;

int len(char *s){
	int i = 0;
	while (i < MAX){
		if (s[i] == '\0') break;
		i++;
	}
	return i;
}

int min(int a, int b){
	if (a < b) return a;
	return b;
}

int max(int a, int b){
	if (a > b) return a;
	return b;
}

void cpy(char* orig, char* dest){
	for (int i=0; i<len(orig); i++){
		dest[i] = orig[i];
	}
	return;
}

char *BigSum(char *a, char *b){
	// Vetores auxiliares para nao afetar a e b pelo possivel deslocamento
	char *s = (char*) malloc(MAX * sizeof(char));
	char *t = (char*) malloc(MAX * sizeof(char));

	cpy(a,s);
	cpy(b,t);

	int l1=len(a), l2=len(b);
	int l=max(l1,l2); // Max_len de s+t = max(s,t) ou max(s,t)+1

	char* ans = (char*) calloc(l+2, sizeof(char));
	int* vis = (int*) calloc(l+1, sizeof(int));

	// Deixa ambos os nums com tamanho l, deslocando para direita
	if (l1 < l)
		for (int i=l1; i>=0; i--)
			s[i+l-l1] = s[i];
	else
		for (int i=l2; i>=0; i--)
			t[i+l-l2] = t[i];

	// Preenche com 0 o deslocado
	for (int i=0; i<l-l1; i++) s[i] = '0';
	for (int i=0; i<l-l2; i++) t[i] = '0';

	int resto = 0; // Resto final, caso sobre resto para uma casa a mais
	for (int i=l-1; i>=0; i--){ // Itera da direita para esquerda
		vis[i] = 1;
		ans[i] += (s[i]-'0') + (t[i]-'0');

		if (ans[i] > 9){
			if (i == 0) resto += ans[i]/10;
			else ans[i-1] += ans[i]/10;
			ans[i] %= 10;
		}
	}

	if (resto > 0){
		// Desloca para direita e volta para string
        for (int i=l; i>0; i--) {
            ans[i] = ans[i-1];
            if (vis[i-1] == 1) ans[i] += '0';
        }
        ans[0] = resto+'0';
    } else {
    	// Volta para string
        for (int i=0; i<l; i++){
            if (vis[i] == 1) ans[i] += '0';
        }
    }

	// Libera os vetores auxiliares
    free(s);
    free(t);
    free(vis);

	return ans;
}

char *BigMult(char *s, char *t){
	int l1=len(s), l2=len(t);
	int l = l1+l2; // Max_len vai ser no maximo s+t

	char* ans = (char*) calloc(l+2, sizeof(char));
	int* vis = (int*) calloc(l+1, sizeof(int));

	char resto = 0;
	for (int i=l1-1; i>=0; i--){
		for (int j=l2-1; j>=0; j--){
			vis[i+j] = 1;
			ans[i+j] += (s[i]-'0')*(t[j]-'0');

			if (ans[i+j] > 9){
				if (i+j == 0) resto += ans[i+j]/10;
				else ans[i+j-1] += ans[i+j]/10;
				ans[i+j] %= 10;
			}
		}
	}

	if (resto > 0){
		for (int i=l; i>0; i--) {
			ans[i] = ans[i-1];
			if (vis[i-1] == 1) ans[i] += '0';
		}
		ans[0] = resto+'0';
	} else {
		for (int i=0; i<l; i++){
			if (vis[i] == 1) ans[i] += '0';
		}
	}

	// Liberando vetor auxiliar
	free(vis);

	return ans;
}

int equal(char* a, char* b){
	if (len(a) != len(b)) return 0;

	for (int i=0; i<len(a); i++){
		if (a[i] != b[i]) return 0;
	}

	return 1;
}

char* fact(char* num){
	char* ans = (char*) malloc(MAX * sizeof(char));
	ans[0] = '1'; // Comeca ans = 1

	char* i = (char*) malloc(MAX * sizeof(char));
	char* plusone = (char*) malloc(MAX * sizeof(char));
	i[0] = '2'; // Comeca i = 2
	plusone[0] = '1'; // Plusone serve como i -> ++ <-

	while (equal( BigSum(num,plusone), i) == 0){ // Se i != num+1
		cpy(BigMult(ans,i), ans); // ans = ans*i

		cpy(BigSum(i,plusone), i); // i++
	}

	// Libera vetores auxiliares
	free(i);
	free(plusone);

	return ans;
}

int main(){
	char* n = (char*) malloc(MAX * sizeof(char));

	printf("Numero para fatorial: ");
	scanf("%s", n);

	printf("%s! = %s\n", n, fact(n));

	return 0;
}

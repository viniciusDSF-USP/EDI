// Adicionar stdio e stdlib quando incluir esta biblioteca

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
	int i;
	for (i=0; i<len(orig); i++){
		dest[i] = orig[i];
	}
	dest[i] = '\0';
	return;
}

char* BigSum(char *a, char *b){
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

char* BigMult(char *s, char *t){
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

int cmp(char* a, char* b){ // -1 (a < b); 0 (a == b); 1 (a > b)
	if (len(a) < len(b)) return -1;
	else if (len(a) > len(b)) return 1;

	for (int i=0; i<len(a); i++){
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}

	return 0;
}

char* stoi(int num){
	char* str = (char*) malloc(MAX * sizeof(char));

	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
	} else {
		int aux = num;
		int i = 0;
		while (aux > 0){
			aux /= 10;
			i++;
		}

		str[i--] = '\0';
		while (num > 0){
			str[i--] = '0'+num%10;
			num /= 10;
		}
	}

	return str;
}

char* fatorial(char* num){
	char* ans = stoi(1); // Comeca ans = 1
	char* i = stoi(2); // Comeca i = 2

	char* um = stoi(1);
	char* numM1 = BigSum(num,um); // num+1
	char* iM1; // i++
	char* ansVi; // ans*i

	while (cmp(numM1, i) == 1){ // Enquanto num+1 > i
		ansVi = BigMult(ans,i);
		cpy(ansVi, ans); // ans = ans*i

		iM1 = BigSum(i,um);
		cpy(iM1, i); // i++

		free(ansVi);
		free(iM1);
	}

	// Libera vetores auxiliares
	free(numM1);
	free(um);
	free(i);

	return ans;
}

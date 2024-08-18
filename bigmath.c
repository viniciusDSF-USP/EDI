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

char* str(int num){
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

void BigDiv2(char* s){
	int l = len(s);
	int i=0;
	for (i=0; i<l; i++) {
		if (i+1 < l) s[i+1] += 10*((s[i]-'0')%2);
		s[i] = (s[i]-'0')/2 + '0';
	}

	if (s[0] == '0'){
		for (i=1; i<=l; i++) s[i-1] = s[i];
	}

	return;
}

void BigInc(char* s){
	int l = len(s);
	int i = l-1;
	s[i] = s[i] + 1;
	while (s[i]-'0' > 9) {
		if (i == 0){
			for (int j=++l; j>=0; j--) s[j] = s[j-1];
			s[0] = '0';
			i++;
		}

		s[i] = (s[i]-'0')%10 + '0';
		s[--i]++;
	}

	return;
}

void BigDec(char* s){
	int l = len(s);
	int i = l-1;
	s[i] = s[i] - 1;
	while (s[i]-'0' < 0) {
		s[i] += 10;
		s[--i]--;
	}
	if (s[0]-'0' == 0){
		for (int i=0; i<l; i++){
			s[i] = s[i+1];
		}
	}

	return;
}

char* BigDiv(char* s, char* t){
	int l1 = len(s), l2 = len(t);
	int l;

	if (l1 <= l2) l = 1;
	else l = l1;

	char* ans = (char*) calloc(l+1, sizeof(char));

	char* aux = str(0);
	if (cmp(t,aux) == 0){ // Divisao por zero
		ans[0] = '@';
		ans[1] = '\0';

		free(aux);
	} else if (cmp(s,t) == -1) { // s < t
		ans[0] = '0';
		ans[1] = '\0';
	} else { // s >= t
		// BUSCA BINARIA
		char* l = str(1);
		char* r = str(1);
		cpy(s, r); // r = s

		char *mid;
		char* mult;
		while (cmp(l,r) <= 0){ // l <= r
			mid = BigSum(l,r);
			BigDiv2(mid); // mid = (l+r)/2

			mult = BigMult(t, mid); // mult = t*mid
			if (cmp(mult, s) == 1){ // if (mult > s)
				cpy(mid, ans); // ans = mid

				cpy(mid, r);
				BigDec(r); // r = mid-1
			} else {
				cpy(mid, l);
				BigInc(l); // l = mid+1
			}

			free(mid);
			free(mult);
		}

		BigDec(ans); // ans = upper_bound - 1

		// METODO ITERATIVO
		/*char *im1 = str(1);
		char *i = str(1);
		char *um = str(1);
		while (cmp(ans, s) == -1){ // ans < s
			cpy(i, im1); // i-1 = i
			aux = BigSum(i,um); // aux = i+1
			cpy(aux, i); // i = i+1
			free(aux);

			aux = BigMult(t, i); // aux = t*i
			cpy(aux, ans); // ans = aux
			free(aux);
		}

		cpy(im1, ans);
		free(um);
		free(im1);
		free(i);*/
	}

	return ans;
}

char* fatorial(char* num){
	char* ans = str(1); // Comeca ans = 1
	char* i = str(2); // Comeca i = 2

	char* um = str(1);
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

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { if (a > b) return a; return b; }
int min(int a, int b) { if (a < b) return a; return b; }
void sumn3(int *v, int n);
void sumn2(int *v, int n);
void sumn(int *v, int n);
void pown(int a, int b);
void powlogn(int a, int b);

int main(){
	int n;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	int *v = (int *) malloc(n * sizeof(int));

	for (int i=0; i<n; i++){
		printf("%d-ésimo inteiro: ", i+1);
		scanf("%d", &v[i]);
	}

	sumn3(v, n);
	sumn2(v, n);
	sumn(v, n);

	int a, b;
	printf("\na^b: ");
	scanf("%d %d", &a, &b);

	pown(a, b);
	powlogn(a, b);

	return 0;
}

void sumn3(int *v, int n){
	int mx=0;

	for (int i=0; i<n; i++)
		for (int j=i, sum; j<n; j++) {
			sum = 0;
			for (int k=i; k<=j; k++) sum += v[k];
			mx = max(mx, sum);
		}

	printf("O(n³) = %d\n", mx);
	return;
}

void sumn2(int *v, int n){
	int *prefix = (int *) malloc(n * sizeof(int));
	for (int i=0; i<n; i++) prefix[i] = 0;
	for (int i=0; i<n; i++) prefix[i] = v[i] + ((i == 0) ? 0 : prefix[i-1]);

	int mx=0;
	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++)
			mx = max(mx, prefix[j] - ((i == 0) ? 0 : prefix[i-1]));

	printf("O(n²) = %d\n", mx);
	free(prefix);
	return;
}

void sumn(int *v, int n){
	int gmx=0x80000001, lmx=0;

	for (int i=0; i<n; i++){
		lmx += v[i];
		gmx = max(gmx, lmx);
		lmx = max(lmx, 0);
	}

	printf("O(n) = %d\n", gmx);
	return;
}

void pown(int a, int b){
	int ans=1;
	for (int i=0; i<b; i++) ans *= a;

	printf("O(n) = %d\n", ans);
	return;
}

void powlogn(int a, int b){
	int ans = 1;
	while (b > 0){
		if (b%2 != 0) ans *= a;
		a = a*a;
		b = b/2;
	}

	printf("O(log(n)) = %d\n", ans);
	return;
}

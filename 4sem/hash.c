#include <stdio.h>
#include <stdlib.h>

typedef struct _map{
	int key;
	int count;
	struct _map *prox;
} map;

const int maxp = 2003;

map *mKey(map m[], int k){
	return &(m[k%maxp]);
};

map *mFind(map m[], int k){
	map *i = mKey(m, k);
	while (i->key != k){
		if (i->prox == NULL) return NULL;
		i = i->prox;
	}
	return i;
}

void mPB(map m[], map *i, int k){
	while (i->prox != NULL){
		i = i->prox;
	}

	map *newm;
	if (i->count == 0) newm = i;
	else {
		newm = (map *) malloc(sizeof(map));
		i->prox = newm;
	}

	newm->key = k;
	newm->count = 1;

	return;
}

void mInsert(map m[], int k){
	map *find = mFind(m, k);
	if (find == NULL){
		mPB(m, mKey(m, k), k);
	} else {
		find->count++;
	}
	return;
}

void mPrint(map m[]){
	map *j;
	for (int i=0; i<maxp; i++){
		if (m[i].count == 0) continue;

		j = &(m[i]);
		while (j != NULL){
			printf("%d: %d\n", j->key, j->count);
			j = j->prox;
		}
	}
	return;
}

int main(){
	map m[maxp];

	for (int i=0; i<maxp; i++) {
		m[i].key = 0;
		m[i].count = 0;
		m[i].prox = NULL;
	}

	mInsert(m, 9);
	mInsert(m, 4);
	mInsert(m, 31);
	mInsert(m, 9);

	mPrint(m);

	printf("%d\n", mFind(m, 9)->count);

	return 0;
}

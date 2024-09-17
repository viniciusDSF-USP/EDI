#include <stdio.h>
#include <stdlib.h>
#include "lib/queueGenerica.h"

int main(){
	int err;
	var u;
	queue F;

	Create(&F);

	u.type = 0;
	u.v.i = 6;
	Push(&F, u, &err);

	u.type = 1;
	u.v.c = 'P';
	Push(&F, u, &err);

	u.type = 2;
	u.v.f = 12.3221;
	Push(&F, u, &err);

	u.type = 3;
	u.v.d = 0.3125529;
	Push(&F, u, &err);

	while (!Empty(&F)){
		Front(&F, &u, &err);

		switch (u.type){
			case 0:
				printf("%d", u.v.i);
				break;
			case 1:
				printf("%c", u.v.c);
				break;
			case 2:
				printf("%.6f", u.v.f);
				break;
			case 3:
				printf("%.15lf", u.v.d);
				break;
			default:
				printf("\nHa um tipo desconhecido na lista!\n");
				break;
		}

		printf(" ");
	}
	printf("\n");

	return 0;
}

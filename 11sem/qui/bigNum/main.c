#include <stdio.h>
#include <stdlib.h>
#include "lib/bignum.h"

int main(){
	Big *num1 = criar("4920");
	Big *num2 = criar("80000");
	
	Big *num3 = somar(num1, num2);
	BigPrint(num1); printf(" + "); BigPrint(num2); printf(" = ");
	BigPrint(num3); printf("\n");

	return 0;
}
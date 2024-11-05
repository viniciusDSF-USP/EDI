#include <stdio.h>
#include <stdlib.h>
#include "lib/bignum.h"

int main(){
	Big *num1 = criar("192713879823497123");
	Big *num2 = criar("1203820193805");
	
	Big *num3 = somar(num1, num2);
	/*BigPrint(num3);*/

	return 0;
}
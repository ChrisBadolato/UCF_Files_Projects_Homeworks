#include <stdio.h>
#include <stdlib.h>

#include "big50.h"

// print an Integer50 (followed by a newline character)
void big50Print(Integer50 *p)
{
	int i;

	if (p == NULL)
	{
		printf("(null pointer)\n");
		return;
	}

	for (i = MAX50 - 1; i >= 0; i--)
		printf("%d", p->digits[i]);
	printf("\n");
}

int main(void)
{
	Integer50 *p;
	Integer50 *q;
	Integer50 *r;

	// Load crypto variable from the file named cryptoVarFile

	// Load the unseeded HW config variable
	
        // Unseeded random number generator should generate
	// the same sequence of numbers in every run
	
	// NB The unseeded variable should have a repeating
	//    pattern of 5 "random" digits - 10 times.
	

	p = loadCryptoVariable("cryptoVarFile");
	q = loadHWConfigVariable(0);
	r = big50Add( p, q);
	big50Print(p); 
	big50Print(q);
	big50Print(r);

	return 0;
}

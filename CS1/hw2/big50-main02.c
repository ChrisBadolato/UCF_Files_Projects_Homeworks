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

	// Load crypto variable from the file named cryptoVarFile
	big50Print(p = loadCryptoVariable("cryptoVarFile"));
	big50Destroyer(p);

	// Load the unseeded HW config variable
	
        // Unseeded random number generator should generate
	// the same sequence of numbers in every run
	
	// NB The unseeded variable should have a repeating
	//    pattern of 5 "random" digits - 10 times.
        big50Print(p = loadHWConfigVariable(0));
	big50Destroyer(p);

	// Load the SEEDED HW config variable

	// SEEDED random number generator should generate
	// a different sequence of numbers in every run

	// NB The SEEDED variable should contain
	//    50 RANDOM digits.
        big50Print(p = loadHWConfigVariable(1));
	big50Destroyer(p);

	return 0;
}

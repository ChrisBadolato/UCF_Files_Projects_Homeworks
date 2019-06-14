#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

int main(int argc, char *argv[])
{
	Integer50 *p;
	Integer50 *q;
	Integer50 *r;
	int seed = 0;
	int fNum = 0;
	char *cryptoFilename;

	// Check if command line parms entered
	// IF none ->EXIT but leave a message
	if (argc == 1)
	  {
	    printf("\n\t usage:\n");
	    printf("\t big50-main04 fibonacciNumber cryptoFilename seedType\n\n");
	    exit(1);
	  }
	fNum = atoi(argv[1]);
	cryptoFilename = argv[2];
	seed = atoi(argv[3]);

	// Load crypto variable from the file named cryptoFilename

	// Load the HW config variable
	p = loadCryptoVariable(cryptoFilename);
	q = loadHWConfigVariable(seed);

        r = fibBig50(fNum, p, q);

        big50Print(p); //print crypto variable
        big50Print(q); //print HW config variable
        big50Print(r); //print F(n)


        big50Rating(); //print the rating (NID,difficulty, & hours)

	return 0;
}

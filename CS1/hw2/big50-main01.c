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

	//50 digits
	big50Print(p = parseString("01234567890123456789012345678901234567890123456789"));
	big50Destroyer(p);

	//<50 digits
	big50Print(p = parseString("354913546879519843519843548943513179"));
	big50Destroyer(p);


	//>50 digits
	big50Print(p = parseString("012345678901234567890123456789012345678901234567899999"));
	big50Destroyer(p);

	//Null digits
	big50Print(p = parseString(NULL));
	big50Destroyer(p);

	//50 digit add
	p = parseString("99999999999999999999999999999999999999999999999999"); //50 9s
	q = parseString("1"); //just a single
	r = big50Add( p, q);
	big50Print(p);
	big50Print(q);
	big50Print(r);

	//50 digit add
	p = parseString("44444444444444444444444444444444444444444444444444"); //50 4s
	q = parseString("55555555555555555555555555555555555555555555555555"); //50 5s
	r = big50Add( p, q);
	big50Print(p);
	big50Print(q);
	big50Print(r);



	return 0;
}

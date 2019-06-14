#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define MAX50 50

typedef struct Integer50
{
  // a dynamically allocated array to hold a 50
  // digit integer, stored in reverse order
  int *digits;
} Integer50;

Integer50 *parseString(char *str);
void big50Print(Integer50 *p);
Integer50 *big50Destroyer(Integer50 *p);


int main () {

    Integer50 *p;
    Integer50 *q;
    Integer50 *r;
    big50Print(p = parseString("01234567890123456789012345678901234567890123456789"));
    big50Destroyer(p);
    big50Print(p = parseString("354913546879519843519843548943513179"));
    big50Destroyer(p);
    big50Print(p = parseString("012345678901234567890123456789012345678901234567899999"));
	big50Destroyer(p);
    big50Print(p = parseString(NULL));
	big50Destroyer(p);
	big50Print(p = parseString("99999999999999999999999999999999999999999999999999")); //50 9s
	big50Print(q = parseString("1")); //just a single 1


    p = parseString("44444444444444444444444444444444444444444444444444"); //50 4s
	q = parseString("55555555555555555555555555555555555555555555555555"); //50 5s
	r = big50Add( p, q);
	big50Print(p);
	big50Print(q);
	big50Print(r);




    //big50Print(p = parseString("01234567890123456789012345678901234567890123456789"));
    return 0;

}


Integer50 *parseString(char *str) {

    int i = 0, strLength = 0, over50;
    Integer50 *ptrP;
    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);


if (str != NULL){

    strLength = strlen(str);
    over50 = strLength - 50;

    while(i < MAX50 ) {

    ptrP->digits[i] = str[strLength-1-i]-'0';

    if(str == NULL){
        printf("Empty");
        ptrP->digits[i] = 0;
    }
    if(strLength > MAX50){
    ptrP->digits[i] = (str[strLength-1-i - over50]-'0');
    }
    if(i > strLength - 1){
        ptrP->digits[i] = str[strLength-1-i]-'0';
        ptrP->digits[i] = 0;
    }
    i++;
    }
}
else {
    return NULL;
}
    return ptrP;

}

Integer50 *big50Destroyer(Integer50 *p) {

 free(p);
 return NULL;

}

Integer50 *big50Add(Integer50 *p, Integer50 *q){

    Integer50 *ptrP;
    int i = 0;

    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);

    if(p != NULL || q != NULL){
        while(i < MAX50) {
            ptrP->digits[i] = q->digits[i] + p->digits[i];
            i++;
        }



    }
    else{
        return NULL;
    }
    return ptrP;


}



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


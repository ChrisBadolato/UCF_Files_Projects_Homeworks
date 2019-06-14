//Christopher Badolato CH432391
//Assignment 6A
//11/8/2018
//ENC3211
/*
This program will take in four user entered characters and create one 32-bit
value with them as an unsigned type. We will shift on the letters to the binary
value in the order they were received.
*/

#include <stdio.h>
    //function prototypes
unsigned packCharacters(unsigned ch1, char ch2);
void display(unsigned result);

int main(){
	char k, l, m, n;
	unsigned result = 1 << 32, result1, result2, result3;
    int c, shiftValue = 8;
        //get the characters from the user.
	printf("Enter first character: ");
	scanf( "%c", &k);
	printf("Enter second character: ");
	scanf(" %c", &l);
    printf("Enter third character: ");
	scanf(" %c", &m);
    printf("Enter fourth character: ");
	scanf(" %c", &n);
    char ch = k;
        //First we must display our currently empty 32 bit result.
	printf("\nResults before shifting and replacing the last 8 bits with %c\n", k);
	display(result);
        //we add our first character to the unsigned results and displays the value
    result = packCharacters(0, k);
    printf("\nResults after shifting and replacing the last 8 bits with %c\n", k);
	display(result);
        //next we will shift our next character onto the unsigned results.
        //we send our previous version of our binary results and our current char
        //to "push it" on the the binary value.
    printf("\nResults before shifting and replacing the last 8 bits with %c\n", l);
    display(result);
    printf("\nResults after shifting and replacing the last 8 bits with %c\n", l);
    result1 = packCharacters(result, l);
	display(result1);
	printf("\nResults before shifting and replacing the last 8 bits with %c\n", m);
	display(result1);
        //adds our next character
    printf("\nResults after shifting and replacing the last 8 bits with %c\n", m);
    result2 = packCharacters(result1, m);
	display(result2);
	printf("\nResults before shifting and replacing the last 8 bits with %c\n", n);
    display(result2);
        //adds and displays our final character.
    printf("\nResults after shifting and replacing the last 8 bits with %c\n", n);
	result3 = packCharacters(result2, n);
    display(result3);
	return 0;
}
    //This function takes our unsigned version of our results and our next character
    //and packs them onto the unsigned binary value by shifting the bits.
unsigned packCharacters(unsigned ch1, char ch2){
	unsigned unsignedPack = ch1;
	unsignedPack <<= 8;
	unsignedPack |= ch2;
	return unsignedPack;
}
    //will display our 32 bit unsigned value as we create new versions of the
    //results as we call it.
void display(unsigned result){
	unsigned bitCount;
	unsigned temp = 1 << 31;
        //prints the unsigned value of the results.
	printf("%7u = ", result);
	for(bitCount=1; bitCount<=32; bitCount++){
		result & temp ? putchar('1'): putchar('0');
		result <<= 1;
		if(bitCount % 8 == 0){
			putchar(' ');
		}
	}
	putchar('\n');
}




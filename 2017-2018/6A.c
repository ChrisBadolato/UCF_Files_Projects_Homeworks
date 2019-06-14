//Christopher Badolato CH432391
//Assignment 6A
//11/8/2018
//ENC3211

//Create a union print out the value as, char, short, int, long.
//for each type we print the value of each type as well as each type in hex.

#include<stdio.h>
union integer{
	char c;
	short s;
	int i;
	long b;
};

int main()
{
        //initialize our union
	union integer unionValue;
        //grab or first char and store it on our union.
        //it will store the same char in each position as different types.
	printf("Enter data type char: ");
	scanf("%c", &unionValue.c);
        //Print the types of the entered char.
	printf("\nBreak down of elements in the union\n");
	printf("char %c\n", unionValue.c);
	printf("short:%hd\n", unionValue.s);
	printf("int %d\n", unionValue.i);
	printf("long %ld\n", unionValue.b);
        //print the hex of each type.
    printf("\nBreak down in hex\n");
    printf("char %x\n", unionValue.c);
	printf("short:%x\n", unionValue.s);
	printf("int %x\n", unionValue.i);
	printf("long %x\n", unionValue.b);
        //do it for a short
	printf("\nEnter data type short: ");
	scanf("%hd", &unionValue.s);
	printf("\nBreak down of elements in the union\n");
	printf("%hd shown as a char: %c\n",  unionValue.c);
	printf("%hd shown as a short: %hd\n", unionValue.s);
	printf("%hd shown as an int: %d\n",  unionValue.i);
	printf("%hd shown as a long: %ld\n", unionValue.b);
        //hex
    printf("\nBreak down in hex\n");
    printf("char %x\n", unionValue.c);
	printf("short:%x\n", unionValue.s);
	printf("int %x\n", unionValue.i);
	printf("long %x\n", unionValue.b);
        //do it for an integer
	printf("\nEnter data type integer: ");
	scanf("%d", &unionValue.i);
	printf("\nBreak down of elements in the union\n");
	printf("char %c\n", unionValue.c);
	printf("short %hd\n",  unionValue.s);
	printf("int %d\n",  unionValue.i);
	printf("long:%ld\n", unionValue.b);
        //hex
    printf("\nBreak down in hex\n");
    printf("char %x\n", unionValue.c);
	printf("short:%x\n", unionValue.s);
	printf("int %x\n", unionValue.i);
	printf("long %x\n", unionValue.b);
        //do it for a long
	printf("\nEnter data type Long ");
	scanf("%ld", &unionValue.b);
	printf("\nBreak down of elements in the union\n");
	printf("char: %c\n", unionValue.c);
	printf("short: %hd\n", unionValue.s);
	printf("int: %d\n", unionValue.i);
	printf("long: %ld\n", unionValue.b);
        //hex
    printf("\nBreak down in hex\n");
    printf("char %x\n", unionValue.c);
	printf("short:%x\n", unionValue.s);
	printf("int %x\n", unionValue.i);
	printf("long %x\n", unionValue.b);

	return 0;
}


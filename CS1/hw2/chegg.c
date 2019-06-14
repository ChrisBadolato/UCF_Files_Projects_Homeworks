

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Fibonacci.h"

// print a HugeInteger (without a newline character)
void hugePrint(HugeInteger *p)
{
   int i;

   if (p == NULL || p->digits == NULL)
   {
       printf("(null pointer)");
       return;
   }

   for (i = p->length - 1; i >= 0; i--)
       printf("%d", p->digits[i]);
}

int main(void)
{
   int i;
   HugeInteger *p, *q, *r;

   // calculate INT_MAX + 1
   p = parseInt(INT_MAX);
   q = parseInt(1);
   r = hugeAdd(p, q);

   // demonstrate overflow
   printf("Overflow style:\n%d + %d = %d\n\n", INT_MAX, 1, INT_MAX + 1);

   // print result of INT_MAX + 1 with HugeIntegers
   printf("HugeInteger style:\n");
   hugePrint(p);
   printf(" + ");
   hugePrint(q);
   printf(" = ");
   hugePrint(r);
   printf("\n\n");

   // free memory
   hugeDestroyer(p);
   hugeDestroyer(q);
   hugeDestroyer(r);


   // now calculate UINT_MAX + 1
   p = parseInt(UINT_MAX);
   q = parseInt(1);
   r = hugeAdd(p, q);

   // demonstrate overflow
   printf("Overflow style:\n%u + %u = %u\n\n", UINT_MAX, 1, UINT_MAX + 1);

   // print result of UINT_MAX + 1 with HugeIntegers
   printf("HugeInteger style:\n");
   hugePrint(p);
   printf(" + ");
   hugePrint(q);
   printf(" = ");
   hugePrint(r);
   printf("\n");

   // free memory
   hugeDestroyer(p);
   hugeDestroyer(q);
   hugeDestroyer(r);


   return 0;
}


Fibonacci.h

#ifndef __FIBONACCI_H
#define __FIBONACCI_H

typedef struct HugeInteger
{
   // a dynamically allocated array to hold the digits of a huge integer
   int *digits;

   // the number of digits in the huge integer (approx. equal to array length)
   int length;
} HugeInteger;


// Functional Prototypes

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q);

HugeInteger *hugeDestroyer(HugeInteger *p);

HugeInteger *parseString(char *str);

HugeInteger *parseInt(unsigned int n);

unsigned int *toUnsignedInt(HugeInteger *p);

HugeInteger *fib(int n);


#endif


Fibonacci.c


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Fibonacci.h"

int powerOf(int num, int power) {

   int product = 1, i = 0;

   if(power == 0)
       return 1;

   for(i = 0; i < power; i++)
       product *= num;

   return product;
}

HugeInteger *cleanMe(HugeInteger *p) {
   free(p);
   p = NULL;

   return p;
}

int howManyDigits(int n) {

   int sum = 0;

   while(n != 0) {
       n /= 10;
       sum++;
   }

   return sum;
}

unsigned int howBigIsMax(unsigned int n) {

   unsigned int sum = 0;

   while(n != 0) {
       n /= 10;
       sum++;
   }

   return sum;
}

void swapper(HugeInteger *p, HugeInteger *q) {

   HugeInteger *tempStruct;

   if(q->length > p->length) {
       tempStruct = p;
       p = q;
       q = tempStruct;
   }

}

HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q) {

   int sum, i;

   HugeInteger *newStruct;

   if(p == NULL || q == NULL)
       return NULL;

   sum = (p->length > q->length ? p->length : q->length);

   newStruct = malloc(sizeof(HugeInteger));

   if(!newStruct)
       return cleanMe(newStruct);

   newStruct->digits = calloc(sum, sizeof(int) * 3);

   if(!newStruct->digits)
       return hugeDestroyer(newStruct);

   swapper(p, q);

   newStruct->length = sum;

   for(i = sum - 1; i >= 0; i--)
       newStruct->digits[i] = p->digits[i];


   for(i = q->length - 1; i >= 0; i--)
       newStruct->digits[i] += q->digits[i];

   for(i = 0; i < newStruct->length - 1; i++) {
       newStruct->digits[i + 1] += newStruct->digits[i] / 10;
       newStruct->digits[i] %= 10;
   }

   if(newStruct->digits[newStruct->length - 1] > 9) {
       if(newStruct->length == 1)
       newStruct->digits = realloc(newStruct->digits, 2 * sizeof(int));
       else
           newStruct->digits = realloc(newStruct->digits, ((newStruct->length + 1) *
           sizeof(int)));
       if(!newStruct->digits)
           return hugeDestroyer(newStruct);
       newStruct->digits[newStruct->length] = 1;
       newStruct->digits[newStruct->length - 1] %= 10;
       newStruct->length++;
   }

   return newStruct;
}


HugeInteger *hugeDestroyer(HugeInteger *p) {

   if(p == NULL)
       return NULL;

   free(p->digits);
   p->digits = NULL;

   p = cleanMe(p);

   return NULL;
}

HugeInteger *parseString(char *str) {

   int i, j = 0, l;

   HugeInteger *newStruct;

   if(str == NULL)
       return NULL;

   newStruct = calloc(1, sizeof(HugeInteger));

   if(!newStruct)
       return cleanMe(newStruct);

   newStruct->length = strlen(str);

   newStruct->digits = calloc(newStruct->length, sizeof(int));

   if(!newStruct->digits)
       return hugeDestroyer(newStruct);

    for(i = newStruct->length - 1; i >= 0; i-- && j++)
        newStruct->digits[i] = (str[j]) - '0';

   return newStruct;
}

HugeInteger *parseInt(unsigned int n) {
   int i;

   HugeInteger *newStruct;

   newStruct = calloc(1, sizeof(HugeInteger));

   if(!newStruct)
       return cleanMe(newStruct);

   newStruct->length = (int)howBigIsMax(n);


   newStruct->digits = calloc(newStruct->length, sizeof(int));

   if(!newStruct->digits)
       return hugeDestroyer(newStruct);

   if(n == 0) {
       newStruct->length = 1;
       return newStruct;
   }

   for(i = newStruct->length - 1; i >= 0; i--) {
       newStruct->digits[i] = n / powerOf(10, i);
       n -= newStruct->digits[i] * powerOf(10,i);
   }


   return newStruct;
}

unsigned int *toUnsignedInt(HugeInteger *p) {

   int i;

   unsigned int *testCase, j = 0, k = howBigIsMax(UINT_MAX);

   if(p == NULL || p->length > k)
       return NULL;

   if(p->length == k)
       if (p->digits[k - 1] > (UINT_MAX / powerOf(10, (int) k - 1)))
           return NULL;

   testCase = calloc(1, sizeof(unsigned int));

   if(!testCase) {
       free(testCase);
       testCase = NULL;
       return NULL;
   }

   for( i = 0; i < p->length + 1; i++) {
       *testCase += ((p->digits[p->length - 1 - i] ) *
           (powerOf(10, p->length - i - 1)));
   }

   return testCase;
}


HugeInteger *fib(int n) {

   HugeInteger *firstFib, *secondFib, *thirdFib, *temp;

   temp = malloc(sizeof(HugeInteger));

   if(!temp)
       return cleanMe(temp);

   temp->digits = calloc(n + 1, sizeof(int));

   if(!temp->digits)
       return hugeDestroyer(temp);

   //temp->digits[0] = 0;
   temp->length = 1;

   firstFib = malloc(sizeof(HugeInteger));

   if(!firstFib)
       return cleanMe(firstFib);

   firstFib->digits = malloc(sizeof(int) * 2);

   if(!firstFib->digits)
       return hugeDestroyer(firstFib);

   firstFib->digits[0] = 0;
   firstFib->length = 1;

   secondFib = malloc(sizeof(HugeInteger));

   if(!secondFib)
       return cleanMe(secondFib);

   secondFib->digits = malloc(sizeof(int));

   if(!secondFib->digits)
       return hugeDestroyer(secondFib);

   secondFib->digits[0] = 1;
   secondFib->length = 1;

   if(n == 0) {
       temp = hugeDestroyer(temp);
       secondFib = hugeDestroyer(secondFib);
       return firstFib;
   }

   if(n == 1) {
       temp = hugeDestroyer(temp);
       firstFib = hugeDestroyer(firstFib);
       return secondFib;
   }



   while (--n != 0) {

       thirdFib = hugeAdd(firstFib, secondFib);

       firstFib = hugeDestroyer(firstFib);

       firstFib = hugeAdd(temp, secondFib);

       secondFib = hugeDestroyer(secondFib);

       secondFib = hugeAdd(temp, thirdFib);

       thirdFib = hugeDestroyer(thirdFib);


   }

   firstFib = hugeDestroyer(firstFib);
   temp = hugeDestroyer(temp);
   thirdFib = hugeDestroyer(thirdFib);
   return secondFib;
}

//Christopher Badolato
//ch432391
//COP 3502
// 04/02/2017
/* This program will find the fibonacci of very large numbers
to a degree of n entered by the user. The numbers can be scanned in from a file,
or entered as a character string.

One thing I was not entirely sure about was fgets does not allow you to get a string if
it is less than 50 digits from the file. It will take in each integer up to string length
but the rest is filled with random numbers. Any feedback would be appreciated.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "big50.h"

Integer50 *parseString(char *str) {

    int i = 0, strLength = 0, over50;
        //declaration of structure pointer
    Integer50 *ptrP;
        //these Mallocs create space in the memory for our integer strings
        //almost every function uses these.
    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);
        //These if statements check to see if our space Malloc'd correctly and are not NULL.
        //each function with a pointer to the structure also contains these if statements.
    if(ptrP == NULL){
        return NULL;
    }
    if(ptrP->digits == NULL){
        return NULL;
    }
    if (str != NULL){
            //length of string, along with how many over 50 the string may be.
        strLength = strlen(str);
        over50 = strLength - 50;
            //if our string is less than 50, it will show the user in the command line and print to standard error.
        if(strLength < MAX50){
            fprintf(stderr, "This string contains less than 50 digits\n");
        }
        while(i < MAX50 ) {
            if (strLength > MAX50){
                    //if our string is greater than 50 we will cut off, from the end what we do not need.
                    //this will also reverse the order of the character string and make them integers.
                ptrP->digits[i] = (str[strLength-1-i - over50]-'0');
            }
                //if our string length is less than 50 we will fill the array with what digits we have, then pad with 0's.
            if(i > strLength - 1){
                ptrP->digits[i] = 0;
            }
            else{
                ptrP->digits[i] = str[strLength-1-i]-'0';
            }
            i++;
        }
    }
        //if our string is NULL return Null.
    else {
        return NULL;
    }
    return ptrP;
}
    //this function frees our pointers so we can refill the space with the next string.
Integer50 *big50Destroyer(Integer50 *p) {

    if(p == NULL){
        return NULL;
    }
    free(p->digits);
    free(p);
    return NULL;
}

Integer50 *big50Add(Integer50 *p, Integer50 *q){
        //declaration of structure pointer
    Integer50 *ptrP;
    int i = 0, remainder, addedValue, carryValue = 0;;
    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);
        //These if statements check to see if our space Malloc'd correctly and are not NULL.
    if(ptrP == NULL){
        return NULL;
    }
    if(ptrP->digits == NULL){
        return NULL;
    }
        //if our P and q are not NULL we will proceed to add the digits.
        //if there is a carry, it will be added to the next value in the digits array.
    if(p != NULL || q != NULL){
        while(i < MAX50) {
            addedValue = q->digits[i] + p->digits[i] + carryValue;
                //our value that is not carried over is stored into the array
            if(addedValue > 9) {
                remainder = addedValue - 10;
                ptrP->digits[i] = remainder;
                carryValue = 1;
            }
            else{
                    //with no carry value the added integer is store into the array.
                ptrP->digits[i] = addedValue;
                carryValue = 0;
            }
            i++;
        }
    }
        //if p or q are NULL return NULL
    else {
        free(ptrP);
        return NULL;
    }
        //return our final added array to main.
    return ptrP;
}

Integer50 *loadCryptoVariable(char *inputString) {
        //input file pointer
    FILE * ifp;
        //declaration of structure pointer
    Integer50 *ptrP;
    char fileNumbers[50];
    int i;
    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);

    if(ptrP == NULL){
        return NULL;
    }
    if(ptrP->digits == NULL){
        return NULL;
    }
        //open the file using the string name sent from main.
    ifp = fopen(inputString, "r");
        //if our file contains information we will scan the file to get the character string
        //this is sent to our parse function to be changed to an integer and reversed.
    if(ifp != NULL){
    fgets(fileNumbers, MAX50+1, ifp);
    ptrP = parseString(fileNumbers);
    }
        //if our pointer is null (our file is empty) we will return NULL.
    else{
        fclose(ifp);
        return NULL;
    }
        //close the file and return the parsed string to main.
    fclose(ifp);
    return ptrP;
}

Integer50 *loadHWConfigVariable(int doSeed){
        //declaration of our random integer digits
    int i = 0, k = 0, randomDigit1, randomDigit2, randomDigit3, randomDigit4, randomDigit5;
    Integer50 *ptrP;
        //declaration of structure pointer
    ptrP = malloc(sizeof(struct Integer50));
    ptrP->digits = malloc(sizeof(int)*50);

    if(ptrP == NULL){
        return NULL;
    }
    if(ptrP->digits == NULL){
        return NULL;
    }
    if (doSeed == 0) {
            //This will load our unseeded 5 random digit integers to a digit from 1-9.
        randomDigit1 = rand()%9+1;
        randomDigit2 = rand()%9+1;
        randomDigit3 = rand()%9+1;
        randomDigit4 = rand()%9+1;
        randomDigit5 = rand()%9+1;
        while( i < 50) {
                //here we are storing these random digits into the slots of the array, repeating 10 times.
                //each time we add a new value, i increases moving down the array.
            ptrP->digits[i] = randomDigit1;
            i++;
            ptrP->digits[i] = randomDigit2;
            i++;
            ptrP->digits[i] = randomDigit3;
            i++;
            ptrP->digits[i] = randomDigit4;
            i++;
            ptrP->digits[i] = randomDigit5;
            i++;
        }
    }
    else {
            //if we need a seeded random variable, this will store 50 random digits into each spot of the array.
        srand(time(NULL));
        while(k < MAX50){
            ptrP->digits[k] = rand()%9+1;
            k++;
        }
    }
        //return the random value string to main.
    return ptrP;
}

Integer50 *fibBig50(int n, Integer50 *first, Integer50 *second){

    if(first == NULL){
        return NULL;
    }
    if(second == NULL){
        return NULL;
    }
        //Our new pointer thirdFib declaration and creation of space.
    Integer50 *thirdFib;
    thirdFib = malloc(sizeof(struct Integer50));
    thirdFib->digits = malloc(sizeof(int)*50);
        //check to see if we've malloc'd correctly
    if(thirdFib == NULL){
        return NULL;
    }
    if(thirdFib->digits == NULL){
        return NULL;
    }
        //n is entered through the command line which will tell us how many times we need to add our values
        //thirdFib will first equal our two sent in arrays added together
        //our first will become the second and second will become the third
        //iterating through the fibonacci sequence until n equals 0.
        // f(n) =  f(n-1) + f(n-2)
    while (n > 0) {
        thirdFib = big50Add(first, second);
        first = second;
        second = thirdFib;
        n--;
    }
        //Finally we return our pointer to the f(n) value to main.
    return thirdFib;
}

void big50Rating(void) {
        //declaration of structure pointer
    big50RatingStruct *ptrP;
    ptrP = malloc(sizeof(struct big50RatingStruct));
        //store my ratings to our pointer struct.
    ptrP->NID = "ch432391";
    ptrP->degreeOfDifficulty = 4;
    ptrP->duration = 30;
        //print them to the stderr.
    fprintf(stderr, "%s\n", ptrP->NID);
    fprintf(stderr, "%f\n", ptrP->degreeOfDifficulty);
    fprintf(stderr, "%f\n", ptrP->duration);
        //free the pointer afterwards.
    free(ptrP);
}








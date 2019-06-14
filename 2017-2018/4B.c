//Christopher Badolato CH432391
//Assignment 4B
//9/30/2018

//This assignment will check the arrays to see if they
//are a palindrome

#include <stdio.h>
    //prototypes for each function, we will reverse the array
    //compare it to the original and then print the original
    //along with whether or not it is a palindrome.
void createReserveArray(int arrayA[], int size);
int compareArray(int arrayA[], int arrayB[], int size);
void printArray(int arrayA[], int size, int palindromeCheck);

int main() {
    int myArray1[]={1,2,3,2,1};
    int myArray2[]={1,2,3,4,1};
    int myArray3[]={1,2,3,3,2,1};
    int myArray4[]={1,2,3,4,2,1};
        //Call our functions on each of the arrays
        //we also send the size of the array.
    createReserveArray(myArray1, 5);
    createReserveArray(myArray2, 5);
    createReserveArray(myArray3, 6);
    createReserveArray(myArray4, 6);
    return 0;
}

void createReserveArray(int arrayA[], int size){
        //We need a new array to store the reverse in
        //and I also create a copy of the original to send
        //to our check functions.
    int tempArray[size];
    int originalArray[size];
    int i;
    int palindromeCheck = -1;
    for(i = 0; i < size; i++){
        originalArray[i] = arrayA[i];
            //will make sure the array is reversed
        tempArray[i] = arrayA[size-i-1];
    }
        //call our check with the originalArray, reversed array, and the size.
        //then call our print function
        //we also create an integer value for our palidromeCheck.
    palindromeCheck = compareArray(originalArray, tempArray, size);
    printArray(originalArray, size, palindromeCheck);
}

int compareArray(int arrayA[], int arrayB[], int size){
    int i, j;
        /*in this function we are comparing each value of the arrays
        (original and reversed) at the same index
        if the values are the same return 0; if different return 1;
        if the values are the same keep looping
        if they are different we can say that its not a palindrome return 1.
        */
    for(i = 0; i < size; i++) {
            if(arrayA[i] == arrayB[i]) {
                continue;
            }
            else {
                return 1;
            }
        }
    return 0;
}

void printArray(int arrayA[], int size, int palindromeCheck){
        //Finally we will print our array, and use our check value
        //to see if it is a palindrome or not.
    int i;
    printf("Array elements are: ");
    for(i = 0; i < size; i++){
            printf("%d ", arrayA[i]);
        }
    printf(" \n");
    if(palindromeCheck != 0){
        printf("The array is not a palindrome");
    }
    else{
        printf("The array is a palindrome");
    }
    printf(" \n \n ");
}

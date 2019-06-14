//Christopher Badolato CH432391
//Assignment 5A
//11/1/2018
//ENC3211

/*
    This program will take the selected string, take our special characters and lower case each letter
    it will then, take a count of each character(histogram) then we will count the length of each
    word within the string.
*/

#include<stdio.h>
#include<string.h>

int main(){
        /*
        Initialize our string variables such as our newly created strings(wordCountString and lowerCase strings)
        To keep track of each letters count We use a 26 by 2 array.
        To keep track of our word counts I created a wordCountTable integer Array.
        */
    char* myString = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
    char currentChar;
    char lowerCase[175];
    char wordCountString[175];
    char letterCountArray[26][2];
    int wordCountTable[8][2];
        //counter, other integers used throughout the program.
    int currentCharInt, wordCountInt = 0;
    int i = 0, counter = 0, j = 0;

    printf("Original Text: \n");
    printf("%s \n\n", myString);
        /*
        loop through the string until null is reached, we will grab each character
        with our currentChar variable, we will check if it is a alphabet letter or
        a space and we will only add those to the new string. We Also will lowerCase each
        character as we go. If it is not one of those types of characters (i.e. # or !) we
        will just add to our counter skipping it.

        I created two strings of the same thing so looping through them twice is easy later.
        */
    while (myString[counter] != '\0'){
		currentChar=myString[counter];
        if(isalpha(currentChar) || currentChar == ' '){
            lowerCase[i] = (char)tolower(currentChar);
            wordCountString[i] = (char)tolower(currentChar);
            counter++;
            i++;
        }
        else{
            counter++;
        }
	}
        //we must set our new Strings last values to 0 so that we can find the end of
        //the string again.
	lowerCase[i] = 0;
    wordCountString[i] = 0;
    printf("Modified Text: \n");
	printf("%s\n\n", lowerCase);



	for(i =0 ; i < 26; i++){
        for(j =0; j < 2; j++){
            letterCountArray[i][0] = i + 97;
            letterCountArray[i][1] = '0';

        }
	}

        /*
        figured I would also try to loop through a string with a for loop.
        This loop will check if the current character in the alphabet. If it is
        we will figure out the integer value for that character and then,
        increment at that character the number of times we've seen that character.
        */
	for (i = 0; lowerCase[i] != '\0'; i++){
        currentChar = lowerCase[i];
        if(isalpha(currentChar)){
            currentCharInt = currentChar - 'a';
            letterCountArray[currentCharInt][1]++;
        }
    }

        //After we populated the letter Count Array we need to print it.
    printf("\n");
    printf("Letter\tCount");
    printf("\n");
    for(i =0; i < 26; i++){
        for(j =0; j < 2; j++){
            printf(" %c", letterCountArray[i][j]);
            printf("\t");
        }
        printf("\n");
	}

        //We must initialize our word count table
        // we will increment down the first column, and initialize the rest to 0.
    for(i =0; i < 9; i++){
        for(j =0; j < 2; j++){
            wordCountTable[i][0] = i;
            wordCountTable[i][1] = 0;
        }
	}
        /*
            Finally we will loop through our other copy of the original String
        we will look at each character with out currentChar variable and keep
        track of the count of each letter between each space.
        */
    counter = 0;
	while (myString[counter] != '\0'){
		currentChar = myString[counter];
        if(currentChar == ' '){
            wordCountTable[wordCountInt][1]++;
            wordCountInt = 0;
        }
        else{
            wordCountInt++;
        }
        counter++;
	}
        //make sure we get the last word on our string!
    wordCountTable[wordCountInt][1]++;
        //Prints out the completed wordCountTable!
    printf(" \n");
    printf("Word Length\tOccurrences");
    printf(" \n");
    for(i = 0; i < 9; i++){
        for(j =0; j < 2; j++){
             printf("%d ", wordCountTable[i][j]);
             printf("\t\t");
        }
         printf("\n");
	}
    return 0;
}

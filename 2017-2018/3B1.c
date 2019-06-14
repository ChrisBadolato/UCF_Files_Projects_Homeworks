//Christopher Badolato CH432391
//Assignment 3B
//9/30/2018
//ENC3211

//This program will the user will play a guessing game of a random number
//between 1 and 1000. They will be asked if they would like to play again or not.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
        //Initialize  our random function based off of the time
        //along with other variables including the character for
        //our yes/no question.
    srand(time(0));
    int randomValue, difference, userGuess;
    char tryAgain = 'y';

    while(tryAgain == 'y' || tryAgain == 'Y'){
            //Create random value between 1 and 1000
            //Prompt for first quess.
        randomValue = rand()%1000+1;
        printf("I have a number between 1 and 1000. \n");
        printf("Can you guess my number? \n");
        printf("Please type your first guess: ");
        scanf("%d", &userGuess);
            //After have our first guess, if it is INCORRECT then we will
            //continue to ask to try again.
            //After determining if the guess is too low or high
            //we will then prompt the use for their nmext guess
        while(userGuess != randomValue){
            if(userGuess < randomValue){
                printf("Too Low. Try again.\n");
            }
            else{
                printf("Too High. Try again.\n");
            }
            scanf("%d", &userGuess);
        }
            //Finally if the guess is correct we will say so
            //then ask to user if they would like to play again.
        printf("Excellent! You guessed the number!\n");
        printf("would you like to try again (y or n)? ");
        scanf(" %c", &tryAgain);
        printf("\n");
    }
    return 0;
}




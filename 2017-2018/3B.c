//Christopher Badolato CH432391
//Assignment 3B
//9/30/2018
//ENC3211

//This program will the user will play a guessing game of a random number
//between 1 and 1000. They will be asked
//if they would like to play again or not.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
        //intialize srand based on the time. Along with other needed variables.
        //tryAgain will start as y so we can enter our loop
    srand(time(0));
    int randomValue, difference, userGuess;
    char tryAgain = 'y';

    while(tryAgain == 'y' || tryAgain == 'Y'){
            //set our first random value
            //prompt user for first guess.
        randomValue = rand()%1000+1;
        printf("I have a number between 1 and 1000. \n");
        printf("Can you guess my number? \n");
        printf("Please type your first guess: ");
        scanf("%d", &userGuess);
            //if they guess the random value
            //ask the user if they would like try again.
            //otherwise we will keep looping checking the
            //users guesses comparing to the random value.
        while(userGuess != randomValue){
            if(userGuess < randomValue){
                printf("Too Low. Try again.\n");
            }
            else{
                printf("Too High. Try again.\n");
            }
            scanf("%d", &userGuess);
        }
            //ask user if they would like to try again.
            //scan the char for yes (y) and no (n).
        printf("Excellent! You guessed the number!\n");
        printf("would you like to try again (y or n)? ");
        scanf(" %c", &tryAgain);
        printf("\n");
    }
    return 0;
}




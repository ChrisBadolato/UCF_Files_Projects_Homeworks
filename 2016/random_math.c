//Christopher Badolato
//this program will tell you the difference between your guess and a secret number

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int guess, diff, secret_num;
    // Seed the random number generator
    srand(time(0));

    //create the secret number

    secret_num = rand()%100+1;

    //Get both guesses

    printf("What number do you guess between 1 and 100?\n");
    scanf("%d", &guess);

    //compute how far off each guess is
    diff = abs(guess-secret_num);

    //output results
    printf("your number was %d.\n", guess);
    printf("The secret number is %d.\n", secret_num);
    printf("you were off by %d.\n", diff);

}

#include <stdio.h>
#include <time.h>
#define MAX 100

int main (){
    int secret, num = 0, guess =- 1;
    int done = 0;

    srand(time(0));

    secret = 1 + rand()%MAX;

    printf("enter your guess.(1 to %d).\n", MAX);

    while (!done) {
        scanf("%d", &guess);

        if (guess == secret) {
            done = 1;
        }
        else if (guess < secret){
            printf("Your guess is too low. Try again\n");
        }
        else {
            printf("Your guess is too high. Try again!\n");
        }

    }
    printf("you won with %d.\n", guess);
    return 0;
}

//Christopher Badolato
//date
//What the program does
//
#include <stdio.h>


int main() {

    //declare variables
    int rate;
    double time;

    //Prompt and also user input
    printf("How fast in mph did you run?\n");
    scanf("%d", &rate);

    //prompt for user input
    printf("how many hours did you run?\n");
    scanf("%lf", &time);

    // this will print the total distance ran
    printf("you ran %lf hours at %d mph for %lf miles\n"
            ,time, rate, rate*time);

    return 0;
}

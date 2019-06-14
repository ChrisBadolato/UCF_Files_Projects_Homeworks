//Christopher Badolato
//9.8.16
//Cop 3223 0003
/*This program will calculate total knitted squares made per week
which can be used to calculated the possible number of blankets
that can be made. */

#include <stdio.h>
    //includes math library for power function
#include <math.h>
#include <stdlib.h>
    //Defined blankets as 60 knitted squares.
#define BLANKET 60


int main() {

    //declaration of variables
    int inital_pop, total_square, square_left, total_blanket;
    float new_pop;

    //collecting user input
    printf("How many people are knitting blanket squares at the start of the week?\n");
    scanf("%d", &inital_pop);

    printf("How many new people are knitting blanket squares each day?\n");
    scanf("%f", &new_pop);

    //Calculates exponential growth function to solve for total squares in one week
    total_square = pow(1 + new_pop, 7) * inital_pop;

    //Calculates total blankets made from squares
    total_blanket = (total_square / BLANKET);

    //Calculates remaining squares for next week
    square_left = (total_square % BLANKET);

    //Final outputs
    printf("%d Blanket squares will be made this week!\n", total_square);
    printf("You will be able to make %d blankets and start next week with %d squares!\n", total_blanket, square_left);

    system("pause");
return 0;
}

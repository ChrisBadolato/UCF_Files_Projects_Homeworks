//Christopher Badolato
//9.1.16
//COP3223C section 0003
/* knit.c This program will allow the user to
find how many hats or sweaters they could make with their
own entered amount of yarn.*/

#include <stdio.h>
    //defined constants for hats and sweaters
#define HAT 225
#define SWEATER 450

int main () {

    //Variable declaration
    int balls_of_yarn, yards_per_ball;
    int total_yarn, hats, sweater;

    //user input of their own yarn
    printf("It takes 225 yards of yarn to make a hat, and 450 yards to make a sweater.\n");
    printf("How many balls of yarn do you have?\n");
    scanf("%d", &balls_of_yarn);

    //use input of yarn distance in yards
    printf("How many yards is each ball of yarn?\n");
    scanf("%d", &yards_per_ball);

    //arithmetic for finding total yarn distance
    total_yarn = balls_of_yarn * yards_per_ball;

    //division used to solve for total hats and sweaters
    hats = total_yarn / HAT;
    sweater = total_yarn / SWEATER;

    //Final output
    printf("You have enough yarn length to make %d hats or %d sweaters.\n", hats, sweater);

    system("pause");
return 0;
}

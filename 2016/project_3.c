//Christopher Badolato
//COP 3223 003
//9.16.16
/*This program will take user inputed dollar value and a percent rate
and find how many scholarships you could give out to students with the money.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main () {
    //variable declaration
    float int_fund, scholarship_fund, rate;
    int two_fifty_dollar = 0, five_hundred_dollar = 0, thousand_dollar = 0;

    //user input
    printf("How much money was in the fund last year?\n");
    scanf("%f", &int_fund);
    printf("And what is your yearly percentage rate?\n");
    scanf("%f", &rate);

    //percentage of funds used for scholarships
    scholarship_fund =  (rate / 100) * int_fund;

    //the while condition keeps the program looping
    while (scholarship_fund > 0) {

        // if the total fund is greater than 1000$ it will run, but only 5 times.
        // subtracts the 1000$ from the funds, then loops back.
        //counter for thousands, thanks to the conditions below it will limit at 5.
        if(scholarship_fund >= 1000 && thousand_dollar < 5) {
            scholarship_fund = scholarship_fund - 1000;
            thousand_dollar = thousand_dollar  + 1;
        }
        //checks if fund is greater than 500
        //adds 1 to the counter until 10 is reached
        //subtracts 500 from the total fund each time.
        else if (scholarship_fund >= 500 && five_hundred_dollar < 10) {
            five_hundred_dollar = five_hundred_dollar + 1;
            scholarship_fund = scholarship_fund - 500;
        //takes as many 250 out as possible
        //adds to the counter until funds reach less-than 250
        }
        else if (scholarship_fund >= 250) {
            two_fifty_dollar = two_fifty_dollar + 1;
            scholarship_fund = scholarship_fund - 250;
        }
        //ends if funds are less than 250
        else {
            break;
        }

    }
    //prints final outputs of scholarships
    printf("%d $1000 scholarships will be awarded to students!\n", thousand_dollar);
    printf("%d $500 scholarships will be awarded to students!\n", five_hundred_dollar);
    printf("%d $250 scholarships will be awarded to students!\n", two_fifty_dollar);

    system("pause");


return 0;
}

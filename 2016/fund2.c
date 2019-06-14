//Christopher Badolato
//COP 3223 0003
//9.23.16
/* This program will allow you to enter a donation or investment amount to a user inputted starting fund.
 You can then print out your total balance and how many investments or donations you have entered. */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    //variable declaration
    int invest_count = 0, donation_count = 0, choice;
    float fund = 0, investment = 0, donation = 0, initial_balance;


            //prompt user for starting balance of fund
        printf("What is your starting balance of the fund?\n");
        scanf("%f", &fund);
        //keeps two variables for the fund, one that changes one that does not.
        initial_balance = fund;
            //prompts user for choice of what they would like to input.
        printf("\nWhat would you like to do?\n");
        printf("\t 1 - Make a donation.\n");
        printf("\t 2 - Make an investment.\n");
        printf("\t 3 - Print the balance of the fund.\n");
        printf("\t 4 - Quit\n");
        scanf("%d", &choice);
            //as long as choice is not 4 the program will continue to run.
            //numbers past 4 will print "Invalid selection" and still loop back.
        while (choice != 4) {
            //takes your choice and matches it with it's case, which will ask user for input.
            switch(choice) {
                    //choice 1, takes entered donation amount, adds it to the funds
                    //It also adds to the number of donations counter.
                case 1:
                    printf("Please enter you donation amount.\n");
                    scanf("%f", &donation);
                    fund = fund + donation;
                    donation_count++;
                    break;

                    //Prompts user for investment amount
                case 2:
                    printf("Please enter your investment amount.\n");
                    scanf("%f", &investment);
                            //If if your fund minus your investment is great than your initial balance
                            //It will also add to the number of investments counter.
                        if (fund - investment >= initial_balance) {
                                fund = fund - investment;
                                invest_count++;
                                break;
                        }
                        //If the amount entered for investment is larger than the donation it allow you to make an investment.
                        //it will take you back to the start of the loop.
                        else;  {
                                printf("\nYou cannot make an investment of that amount!\n");
                                break;

                        }


                    //this last case will print out your total balance and total number of donations and investments
                    //It will also bring you back to the start of the loop
                case 3:
                    printf("\nYour total balance is now $%.2f.\n", fund);
                    printf("Your total donations has reached %d.\n", donation_count);
                    printf("Your total investments has reached %d.\n", invest_count);
                    break;

                    //if any integer greater than 4 is entered into the switch the loop will end.
                default:
                    printf("\nYou did not make a valid selection.\n");
                    break;
    }

            //this puts the menu within the loop
            //allows the menu to be shown after the first three cases
        printf("\nWhat would you like to do?\n");
        printf("\t 1 - Make a donation.\n");
        printf("\t 2 - Make an investment.\n");
        printf("\t 3 - Print the balance of the fund.\n");
        printf("\t 4 - Quit\n");
        scanf("%d", &choice);
    }

     //after the loop has ended it will print the final balance of the fund and the counters.
    printf("Your final balance in the fund is now $%.2f.\n", fund);
    printf("Your total donations has reached %d.\n", donation_count);
    printf("Your total investments has reached %d.\n", invest_count);

    system("pause");

    return 0;
}

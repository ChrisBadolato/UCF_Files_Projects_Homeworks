//Christopher Badolato CH432391
//Assignment 1B
//8/27/2018

//This program will print the interest charged of a loan
//by calculating simple interest.

#include <stdio.h>
#include <stdlib.h>




int main() {

        //Initalize all values as floats for simple calculation of interest.
    int quit = -1;
    float loanPrincipal = 0, interestRate = 0;
    float interestCharge = 0, termOfLoan = 0;
        //loop until our loan value is -1 or is somehow initialized as -1.
    while(loanPrincipal != quit){
        printf("Enter loan principal (-1 to end): ");
        scanf("%f", &loanPrincipal);
            //if our loan principal DOES NOT equal -1, get the rest of our values
            // then we perform the calculation
        if(loanPrincipal != quit){
            printf("Enter interest rate: ");
            scanf("%f", &interestRate);
            printf("Enter term of loan in days: ");
            scanf("%f", &termOfLoan);
            interestCharge = loanPrincipal * interestRate * (termOfLoan/365);
            printf("The interest charge is $%.2f\n\n", interestCharge);
            //if our value for loan principal is -1 break the loop
            //and exit the program.
        }
        else{
            break;
        }
    }
    return 0;
}

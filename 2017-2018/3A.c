//Christopher Badolato CH432391
//Assignment 3A
//9/30/2018
//ENC3211

//this program calculates the function x^2 + 5x + 6;

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    //Function prototype for our calculation function.
float calculation(float);

int main() {
        //Variable declaration, also grabbing of our value from the user.
        //we will continue to loop unless our entered value from the user i
    float functionSolved, enteredValue;
    printf("This program evaluates x^2 + 5x + 6\n\n");
    printf("*** Note: Invalid values will terminate the program ***\n\n");
    while(1){

        printf("Enter a decimal between -100.0 and 100.0 :");
        scanf("%f", &enteredValue);
            //if our value from the user is outside of our range,
            //we need to break the loop and exit the program.
            //otherwise, send the users value to the calculation function.
        if(enteredValue > -100.0 && enteredValue < 100.0){
            functionSolved = calculation(enteredValue);
            printf("f(%.4f) = %.4f \n\n", enteredValue, functionSolved);
        }
        else{
            printf("%.4f is invalid. Good bye", enteredValue, functionSolved);
            break;
        }
    }
    return 0;
}
    //calculates our function using the power function pow(x , 2), (x^2)
    //this will square our x, we will then calculate the rest of the function
    //then send the value back to main.
float calculation(float x){
    float functionSolved;
    functionSolved = pow(x , 2) + (5 * x) + 6;
    return functionSolved;
}

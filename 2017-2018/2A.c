//Christopher Badolato
//ENC 3211 03
//Ch432391
//9/27/18

#include<stdio.h>
void main(){
        //variable declarations.
    int currentValue, headerValue, total, i = 1;
            //get number of values to be entered from user.
        printf("Please enter number of values to be entered: ");
        scanf("%d", &headerValue);
            //ask for our first value so we can set the total.
    if(headerValue != 0){
        printf("Please enter number #1: ");
        scanf("%d", &currentValue);
        total = currentValue;
            //add the values entered by the user until we reach that
            //headerValue they originally entered
            //currentValue is the value entered each loop by the user.
        for(i=2; i<=headerValue; i++){
            printf("Please enter number #%d: ", i);
            scanf("%d", &currentValue);
            total = total + currentValue;
        }
        //finally print the total.
    printf("The total number is %d ", total);
    }
    return 0;
}

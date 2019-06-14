//Christopher Badolato
//ENC 3211 03
//Ch432391
//9/27/18

#include<stdio.h>
void main(){
    int factorial = 0, nextValue, factorialSolved;
        //while -1 is not entered by the user we can keep calculating factorials
    while(factorial != -1){
        printf("Please enter a number between 1 and 10 for factorial calculation(-1 to end): ");
        scanf("%d", &factorial);
            //start our factorial calculation at the first entered value
        factorialSolved = factorial;
            //starting at the next value below the first one entered we will want to
            //then start multiplying. We then decrement
            //the "nextValue" we multiply our final "factorialSolved" value.
        for(nextValue = factorial - 1; nextValue > 0; nextValue--){
            factorialSolved = factorialSolved * nextValue;
        }
        printf("factorial for %d is %d\n\n", factorial, factorialSolved);
    }
    return 0;
}

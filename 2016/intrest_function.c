#include <stdio.h>
#include <math.h>

double mypow(double base, int exponent);

int main () {
    double rate, factor;
    int numyears;

    //get user input
    printf("What percent intrest does your account earn?\n");
    scanf("%lf", &rate);

    printf("over how many years??\n");
    scanf("%lf", &numyears);

    // percent to decimal
    rate /= 100;

    factor = mypow(1 + rate, numyears);

    printf("your money will multiply by a factor of %lf\n", factor);


return 0;
}

//exponent cannot = 0
//will return base raised to the power exponent.
double mypow(double base, int exponent) {
    double answer = 1;
    int i;

    for(i=0; i<exponent; i++) {
        answer = answer * base;
    }

    return answer;
}

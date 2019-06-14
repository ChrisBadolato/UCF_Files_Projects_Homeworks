#include <stdio.h>

void accrue_interest(float* ptrBal, float rate);

int main () {

    float money, perc;
    int years, i;
    printf("How much money do you want to invest?\n");
    scanf("%f", &money);
    printf("What is the interest rate it accrues, as a percent\n");
    scanf("%f", &perc);
    printf("How many years do you want to invest?\n");
    scanf("%d", &years);

    for (i=1; i <= years; i++){
        accrue_interest(&money, perc);
        printf("After %d years you will have %.2f.\n", i, money);

    }

return 0;
}

void accrue_interest(float* ptrBal, float rate) {
    *ptrBal = *ptrBal*(1 + rate/100.0);
}

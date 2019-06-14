#include <stdio.h>
#include <math.h>
#define DELTA 0.000001

int main () {
int n, try_div;
int start, end;
int is_prime;


printf("Enter the starting value of your range.\n");
scanf("%d", &start);
printf("Enter the ending value of your range.\n");
scanf("%d", &end);

if (start < 2)
    start = 2;
    printf("The primes from %d to %d: ", start, end);
for(n=start; n<=end; n++) {
    is_prime = 1;

    for (try_div=2; try_div <= sqrt(n); try_div++){
        if (n%try_div == 0){
            is_prime = 0;
            break;
        }

}
if(is_prime)
    printf("%d is a prime number.\n", n);

}
printf("\n");

return 0;
}

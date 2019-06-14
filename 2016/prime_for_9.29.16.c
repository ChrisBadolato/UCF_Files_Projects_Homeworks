#include <stdio.h>
#include <math.h>
int main () {
int n, try_div;
int is_prime = 1;


printf("Enter n, to test for primality.\n");
scanf("%d", &n);

if (n < 2)
    is_prime = 0;

for (try_div=2; try_div <= sqrt(n); try_div++){
    if (n%try_div == 0){
        is_prime = 0;
        break;
    }

}
if(is_prime)
    printf("%d is a prime number.\n", n);
else
    printf("%d is NOT a prime number.\n", n);


return 0;
}

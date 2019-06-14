#include <stdio.h>
int main () {

int i, n = 6, j;

for (i=n-1; i>=0; i--){

    for (j=1; j<=i; j++)
    printf(" ");
    int stars = n - i;

    for(j=1; j<=stars; j++)
    printf("*");
    printf("\n");

}


return 0;
}

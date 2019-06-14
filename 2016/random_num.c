#include <stdio.h>
int main() {

    srand(time(0));

    printf("%d\n", rand()%1000000+1);
    printf("%d\n", rand()%1000+1);
    printf("%d\n", rand()%100+1);
    printf("%d\n", rand()%100+1);
    printf("%d\n", rand()%100+1);

    return 0;
}

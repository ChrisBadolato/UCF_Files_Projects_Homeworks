#include <stdio.h>
#include <stdlib.h>

int main () {

    int *B, *A;

    A = (int *)malloc(sizeof(int));
    B = (int *)malloc(sizeof(int));
    *A = 19;
    *B = 5;
    printf("*A %d\n", *A);
    printf("*B %d\n", *B);
    printf("A %d\n", A);
    printf("B %d\n", B);

    *A = *B;
    printf("*A = *B\n");
    printf(" *A%d\n", *A);
        printf("*B %d\n", *B);
    *B = 7;
    printf("*B = 7;\n");
        printf("A %d\n", A);
    printf("B %d\n", B);
    printf("*A%d\n", *A);
    printf("*B\n", *B);
    A = B;
    printf("A = B\n");
    printf("*A %d\n", *A);
    printf("*B %d\n", *B);
    printf("A %d\n", A);
    printf("B %d\n", B);



    return 0;

}

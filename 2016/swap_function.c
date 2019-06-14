#include <stdio.h>

void swap(int* ptrA, int* ptrB);

int main () {
    int x = 3, y = 7;
    swap(&x,&y);
    printf("x = %d, y = %d", x, y);

return 0;
}

void swap(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

return;
}

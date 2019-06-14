#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINDEX 100
int main (void) {
    int A[MAXINDEX];
    int i;

    //Initilize the array A to square of ints makew a[17] negative.

    for(i=0; i<MAXINDEX; i++)
        A[i] = i*i;
        A[17] = -A[17];
        printf("First Negative integer in A is found at %d. /n", Find(A));
    return 0;
}

int Find (int A[]) {
    int j;
    for (j=0; j<MAXINDEX; j++) {
        if(A[j] < 0) {
            return j;
        }
    }
    return -1;
}

/*int main (void) {
    int A[MAXINDEX];
    int i;

    //Initilize the array A to square of ints makew a[17] negative.

    for(i=0; i<MAXINDEX; i++)
        A[i] = i*i;
        A[17] = -A[17];
        printf("First Negative integer in A is found at %d. /n", Find(A));

}
*/

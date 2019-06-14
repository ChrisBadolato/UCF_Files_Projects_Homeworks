#include <stdio.h>
#define SIZE 11

int main () {
int pascaltri[SIZE][SIZE];
int r, c;

//initialize beginning and end of each row to 1
for(r=0; r<SIZE; r++) {
    pascaltri[r][0] = 1;
    pascaltri[r][r] = 1;
}


//fill in the table
for (r=2; r<SIZE; r++)
    for(c=1; c<r; c++)
        pascaltri[r][c] = pascaltri[r-1][c-1] + pascaltri[r-1][c];


//loop through each row of the table
for(r=0; r<SIZE; r++) {
    //loop through each value of the row
        for (c=0; c<=r; c++)
        printf("%4d", pascaltri[r][c]);
        printf("\n");


}

return 0;
}

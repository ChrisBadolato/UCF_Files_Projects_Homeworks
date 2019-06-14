
#include <stdio.h>
#define SIZE 5

int main () {

int row, col;
int multtable[SIZE][SIZE];
//store the table
for(row=0; row < SIZE; row++)
    for(col=0; col < SIZE; col++)
        multtable[row][col] = (row+1)*(col+1);

        //print column headers

//go through each row
for(row=0; row<SIZE; row++) {
        //print out the row header

    for(col=0; col<SIZE; col++)
        printf("%4d", multtable[row][col]);
    //go to next row
        printf("\n");
}




return 0;
}

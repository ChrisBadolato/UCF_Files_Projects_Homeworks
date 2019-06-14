//Christopher Badolato CH432391
//Assignment 1C
//8/27/2018

//This program will create a hollow square of the length of the user input
//using for loops to fill out the square and place asterisks where needed.


#include <stdio.h>
#include <stdlib.h>

int main() {
        //initialize our row and column values to 0.
    int squareSide, row = 0, column = 0;
        //Get square size from users.
    printf("Enter the size of the hollow square: ");
    scanf("%d", &squareSide);
        //First we need to draw the top
        //add one each iteration to go through each row.
    while(row < squareSide){
        printf("*");
        row++;
    }
    printf("\n");
    row = 2;
        /*since we have already printed the top we will need to skip to our
        second row and start printing there.
        while our row value is less than the square size AND
        while our columns value is less than our square size we want to print *
        ONLY on our first and last columns.
            */
    while(row < squareSide){
        while(column < squareSide){
                //makes sure we only print on the first and last columns.
            if(column == squareSide -1 || column == 0){
                printf("*");
            }
                //otherwise print a space.
            else{
                printf(" ");
            }
                //go to the next column.
            column++;
        }
            //reset the column value each row we draw and also print a new line.
        column = 0;
        row++;
        printf("\n");
    }
        //reset our row value and draw the bottom of the square to complete the box.
    row = 0;
    while(row < squareSide){
        printf("*");
        row++;
    }
    return 0;
}

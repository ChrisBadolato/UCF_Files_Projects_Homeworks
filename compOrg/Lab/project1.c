// Christopher Badolato 3064088
// 2/25/2019
// EEL3801 0011
// this code will conduct the given functions from project 1.
// It represents the MIPS code we are writing, which involves solving
// multiplication, division, and mod, without using any of there designated functions

#include <stdio.h>

int main(){
        //initializes variables, gets user input for calculations
    int F, G, A, B, C, D, i = 0, temp1 = 0, temp2 = 0;
    int h_quotient = 0, h_remainder = 0, i_quotient = 0, i_remainder = 0, j_remainder = 0;
    printf("please enter values for A,B,C,D \n");
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
        //F = (A x A) – (B x D)
    for(i = A; i > 0; i--){
        temp1 = temp1 + A;
    }
    for(i = B; i > 0; i--){
        temp2 = temp2 + D;
    }
        //subtract our two values for F and reset temps
    F = temp1 - temp2;
    temp1 = 0;
    temp2 = 0;

    for(i = A; i > 0; i--){
        temp1 = temp1 + D;
    }
    for(i = C; i > 0; i--){
        temp2 = temp2 + 6;
    }
        //Add our two values for G
        //print f and g
    G = temp1 + temp2;
    printf("F_ten: %d\n", F);
    printf("G_ten: %d\n", G);
        //reset our temp values to equal F and G
        //calculate h_quotient and h_remainder
    temp1 = F;
    temp2 = G;
    while(temp1 >= temp2){
    temp1 = temp1 - temp2;
    h_quotient++;
    }
    h_remainder = temp1;
        //reset our temporary values
        //calculates i_quotient and i_remainder
    temp1 = F + G;
    temp2 = h_quotient;
    while(temp1 >= temp2){
        temp1 = temp1 - temp2;
        i_quotient++;
    }
    i_remainder = temp1;
        //reset our temporary values
        //calculate j_remainder
    temp1 = F - G;
    temp2 = i_quotient;
    while(temp1 >= temp2){
        temp1 = temp1 - temp2;
    }
    j_remainder = temp1;
        //output the final results.
    printf("h_quotient %d\n", h_quotient);
    printf("h_reminder %d\n", h_remainder);
    printf("i_quotient %d\n", i_quotient);
    printf("i_remainder %d\n", i_remainder);
    printf("j_remainder %d\n", j_remainder);
    return 0;
}

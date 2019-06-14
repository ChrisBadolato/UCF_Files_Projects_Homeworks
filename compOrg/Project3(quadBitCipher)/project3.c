/*
Christopher Badolato
4/8/2019
EEL 3801 0011
Project 3
This program is a C prototype of the QuadMinMixer as well as the QuadBitCipher
Takes two 32 bit input values, grabs the minimum of each group of four bits between the two and creates
a new output Z. The Hexadecimal frequency is then taken of the output value Z.
*/

#include <stdio.h>

    //Function prototypes
unsigned QuadMinMixer(unsigned x, unsigned y);

int main (){
        //Initialize frequency array, loop counter as well as temps and mask.
    int count[16], i;
    unsigned x, y, z, temp;
    unsigned mask = 0x0000000F;
        //get user inputs of x and y.
    scanf("%u", &x);
    scanf("%u", &y);
        //Call QuadMinMixer with x and y and store the output in z.
        //Print the output
    z = QuadMinMixer(x,y);
    printf("QuadMinMixer = ");
    printf("0x%x\n", z);
       //Initialize count array.
    for(i = 0; i < 16; i++){
        count[i] = 0;
    }
        //To start our cipher we must first mask our first set of 4 bits from Z.
        //and also increment the frequency count at those 4-bits
    temp = mask & z;
    count[temp]++;
        //After the first iteration we can loop through the rest.
        //We shift the mask by 4 bits each loop creating a mask of z each iteration
        //as well as taking a frequency count at the index of that temporary stored mask.
    for(i = 0; i < 7; i++){
         z = z >> 4;
         temp = z & mask;
         count[temp]++;
    }
        //Finally we can the array (backwards for our expected output.)
    printf("QuadBitCipher = ");
    for(i = 15; i >= 0; i--){
        printf("%d", count[i]);
    }
    return 0;
}

unsigned QuadMinMixer(unsigned x, unsigned y){
    unsigned tempx = 0, tempy = 0, result = 0;
    int i;
    unsigned mask = 0x0000000F;
        //create the temps for our FIRST set of 4-bits to be compared.
    tempx = x & mask;
    tempy = y & mask;
        //We want to "or", or add the minimum of the two temp values to the result.
        //if x is larger take y.
        //otherwise take x.
    if(tempx >= tempy){
        result = result | tempy;
    }
    else{
        result = result | tempx;
    }
        //After our first iteration we can continue shifting the mask left until we've masked the other 7
        //remaining groups of 4-bits or hex value.
    for(i=0; i < 7; i++){
        mask = mask << 4;
        tempx = x & mask;
        tempy = y & mask;
            //if x is greater take y
            //other wise take x.
        if(tempx >= tempy){
            result = result | tempy;
        }
        else{
            result = result | tempx;
        }
    }
        //Finally we return the results.
    return result;
}




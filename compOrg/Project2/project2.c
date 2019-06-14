// Christopher Badolato 3064088
// 3/18/2019
// EEL3801 0011
/* this code will conduct the given functions from project 2.
It represents the MIPS code we are writing, which involves creating a histogram
using only the letts from "UCF KNIGHTS" the string entered must be LOWERCASE it does
not .
*/

#include <string.h>
#include <stdio.h>

int main(){
        //created integer variables to represent the count at each letters
        //as well as grabs our string length, This code only works if entered string
        //is all lowercase
    int loopCounter = 0, strLen, charAsciiValue;
    int u = 0, c = 0, f = 0, k = 0, n = 0 ,i = 0 ,g = 0, h = 0, t = 0,s = 0;
    char* string = "looming just beyond the outfield and over harper's left shoulder was his mean-mugging face, edited into an image on display on the spectrum field video board. on the protective over-dugout netting just behind harper and others sitting at a red-clothed table on the dugout -- boras, phillies owner john middleton and klentak -- were posters of magazines depicting harper from cover shoots he had with espn the magazine and sports illustrated";
    strLen = strlen(string);
        //Checks each char in the string  to see if it is part of our UCFKNIGHTS char list
        // we will add 1 to the count if the "see" one of our selected characters.
    for(loopCounter = 0; loopCounter < strLen; loopCounter++){
        charAsciiValue = (int)string[loopCounter];
            //u
        if(charAsciiValue == 117){
            u++;
        }
            //c
        else if(charAsciiValue == 99){
            c++;
        }
            //f
        else if(charAsciiValue == 102){
            f++;
        }
            //k
        else if(charAsciiValue == 107){
            k++;
        }
            //n
        else if(charAsciiValue == 110){
            n++;
        }
            //i
        else if(charAsciiValue == 105){
            i++;
        }
            //g
        else if(charAsciiValue == 103){
            g++;
        }
            //h
        else if(charAsciiValue == 104){
            h++;
        }
            //t
        else if(charAsciiValue == 116){
            t++;
        }
            //s
        else if(charAsciiValue == 115){
            s++;
        }
            //Go to the next character in the string once we have checked
            //each character we'd like to make the histogram for. "ucfknights"
        else{
            continue;
        }
    }
        //prints our integer histogram.
    printf("u: %d\n", u);
    printf("c: %d\n", c);
    printf("f: %d\n", f);
    printf("k: %d\n", k);
    printf("n: %d\n", n);
    printf("i: %d\n", i);
    printf("g: %d\n", g);
    printf("h: %d\n", h);
    printf("t: %d\n", t);
    printf("s: %d\n", s);
    printf("\n");

        //Based on the values from the histogram above we will print pounds or
        //"hashtags" for each character count by looping through that character count.
        //u
    printf("u: ");
    for(loopCounter = 0; loopCounter < u; loopCounter++){
        printf("#");
    }
    printf("\n");
        //c
    printf("c: ");
    for(loopCounter = 0; loopCounter < c; loopCounter++){
        printf("#");
    }
    printf("\n");
        //f
    printf("f: ");
    for(loopCounter = 0; loopCounter < f; loopCounter++){
        printf("#");
    }
    printf("\n");
        //k
    printf("k: ");
    for(loopCounter = 0; loopCounter < k; loopCounter++){
        printf("#");
    }
    printf("\n");
        //n
    printf("n: ");
    for(loopCounter = 0; loopCounter < n; loopCounter++){
        printf("#");
    }
    printf("\n");
        //i
    printf("i: ");
    for(loopCounter = 0; loopCounter < i; loopCounter++){
        printf("#");
    }
    printf("\n");
        //g
    printf("g: ");
    for(loopCounter = 0; loopCounter < g; loopCounter++){
        printf("#");
    }
    printf("\n");
        //h
    printf("h: ");
    for(loopCounter = 0; loopCounter < h; loopCounter++){
        printf("#");
    }
    printf("\n");
        //t
    printf("t: ");
    for(loopCounter = 0; loopCounter < t; loopCounter++){
        printf("#");
    }
    printf("\n");
        //s
    printf("s: ");
    for(loopCounter = 0; loopCounter < s; loopCounter++){
        printf("#");
    }
    return 0;
}

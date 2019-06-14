#include <string.h>
#include <stdio.h>
char string[] = "a string,of ,,tokens;and other words";
char *token;

int main(void) {

    token = strtok(string," ,"); /*There are two delimiters here*/

    while (token != NULL){

    printf("The token is:  %s\n", token);
    token = strtok(NULL," ,;");

 }
}

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]){

    int i, sum = 0;

    printf("argc = %d\n", argc);
    printf("lets see what is in argv[]\n");


    for(i = 1; i<argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
        //atoi makes
    }



    return 0;
}

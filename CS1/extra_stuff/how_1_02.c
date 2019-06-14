#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airPdata.h"
#define LENGTH 60
#define NUMVARS 15
#define AIRPORTS 1000



int main () {
    FILE * ifp;


    char filename[LENGTH], site_let[AIRPORTS], *site_num;
    int  x, j;

    struct airPdata airport_num[AIRPORTS];


    printf("Please enter the airport input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    if (ifp == NULL) {
        printf("Could not open %s", filename);
    }

    while(fscanf(ifp, "%s", site_let) != EOF){
        printf("read in string: %s \n", site_let);
       // site_num = strtok(site_let,",");
       //printf("site_num %s\n", site_num);
       //site_num = strtok(EOF,",");
       //printf("site_num %s\n", site_num);
    }

   // site_num = strtok(site_let,",");
    //printf("site_num %s", site_num);

    fclose(ifp);
    return 0;
}

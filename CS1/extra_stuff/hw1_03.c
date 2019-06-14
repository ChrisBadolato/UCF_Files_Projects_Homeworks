#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aairPdata.h"
#define LENGTH 60
#define NUMVARS 15
#define AIRPORTS 1000



int main (int argc, char* argv[]) {
    FILE * ifp;


    char filename[LENGTH], site_let[AIRPORTS], *site_num;
    int  i = 0, j = 0;

    struct airPdata airport_num[LENGTH];


    printf("Please enter the airport input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    if (ifp == NULL) {
        printf("Could not open %s", filename);
    }

    for(i=0; i<=sizeof(site_let); i++) {
    fgets(site_let, sizeof(site_let), ifp);
        j = 0;
        site_num = strtok(site_let,",");

        while (site_num != NULL){
            if( j == 0){
                airport_num->siteNumber = malloc(sizeof(char)* 25);
                strcpy(airport_num->siteNumber, site_num);
                printf("\tsite number %s\n", airport_num->siteNumber);
                if(site_let == "  "){
                    break;
                }

            }
            if(j == 1){
                airport_num->locID = malloc(sizeof(char)* 4);
                strcpy(airport_num->locID, site_num);
                printf("\tlocal id: %s\n", airport_num->locID);
            }
            if(j == 2) {
                airport_num->fieldName = malloc(sizeof(char)* 30);
                strcpy(airport_num->fieldName, site_num);
                printf("\tField name: %s\n", airport_num->fieldName);
            }
            if(j == 3) {
                airport_num->city = malloc(sizeof(char)* 30);
                strcpy(airport_num->city, site_num);
                printf("\tcity: %s\n", airport_num->city);
            }
            if(j == 4) {
                airport_num->state = malloc(sizeof(char)* 25);
                strcpy(airport_num->state, site_num);
                printf("\tstate: %s\n", airport_num->state);
            }
            if(j == 8) {
                airport_num->latitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->latitude, site_num);
                printf("\tlat: %s\n", airport_num->latitude);
            }
            if(j == 9) {
                airport_num->longitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->longitude, site_num);
                printf("\tlong: %s\n", airport_num->longitude);
            }
            if(j == 14) {
                airport_num->controlTower = site_num;
                printf("\tcontrol tower: %c\n", airport_num->controlTower);
            }
           // printf("J: %d\n", j);

          //  printf("First number: %s\n", site_num);
            site_num = strtok(NULL,",");
        j++;

        }

    }
    free(airport_num->siteNumber);
    free(airport_num->locID);
    free(airport_num->fieldName);
    free(airport_num->city);
    free(airport_num->state);
    free(airport_num->latitude);
    free(airport_num->longitude);
    free(airport_num->controlTower);

    fclose(ifp);
    return 0;
}

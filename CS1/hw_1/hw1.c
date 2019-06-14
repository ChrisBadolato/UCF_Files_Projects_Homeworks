#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airPdata.h"
#define LENGTH 60
#define NUMVARS 15
#define AIRPORTS 1000



int main (int argc, char* argv[]) {
    FILE * ifp;


    char filename[LENGTH], airports[AIRPORTS], *airport_info;
    int  i = 0, j = 0;

    struct airPdata airport_num[LENGTH];


    printf("Please enter the airport input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    if (ifp == NULL) {
        printf("Could not open %s", filename);
    }
    printf("%-14s %-12s\t %-20s\t %-20s\t %-10s\t %-15s %-15s %-s\n", "Site Number", "Local ID", "Field Name", "City", "State", "Latitude", "Longitude", "Control Tower");

    for(i=0; i<=sizeof(airports); i++) {
    fgets(airports, sizeof(airports), ifp);

    if (feof(ifp)) {
        break;
    }

        j = 0;
        airport_info = strtok(airports,",");

        while (airport_info != NULL){
            if( j == 0){
                airport_num->siteNumber = malloc(sizeof(char)* 25);
                strcpy(airport_num->siteNumber, airport_info);
                printf("%-10s\t", airport_num->siteNumber);
            }
            if(j == 1){
                airport_num->locID = malloc(sizeof(char)* 4);
                strcpy(airport_num->locID, airport_info);
                printf("%-5s\t", airport_num->locID);
            }
            if(j == 2) {
                airport_num->fieldName = malloc(sizeof(char)* 30);
                strcpy(airport_num->fieldName, airport_info);
                printf("%-30s\t", airport_num->fieldName);
            }
            if(j == 3) {
                airport_num->city = malloc(sizeof(char)* 30);
                strcpy(airport_num->city, airport_info);
                printf("%-20s\t", airport_num->city);
            }
            if(j == 4) {
                airport_num->state = malloc(sizeof(char)* 25);
                strcpy(airport_num->state, airport_info);
                printf("%-10s\t", airport_num->state);
            }
            if(j == 8) {
                airport_num->latitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->latitude, airport_info);
                printf("%-10s\t", airport_num->latitude);
            }
            if(j == 9) {
                airport_num->longitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->longitude, airport_info);
                printf("%-20s\t", airport_num->longitude);
            }
            if(j == 14) {
                airport_num->controlTower = airport_info;
                printf("%-20c", airport_num->controlTower);
            }
;
            airport_info = strtok(NULL,",");
        j++;

        }
    printf("\t\n");
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airPdata.h"
#define LENGTH 60
#define NUMVARS 15
#define AIRPORTS 1000

//void site_num(char * siteNumber);

int main () {
    FILE * ifp;


    char filename[LENGTH], site_let[AIRPORTS], *site_num, x;
    int  i = 0, j = 0;

    struct airPdata airport_num[AIRPORTS];


    printf("Please enter the airport input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    if (ifp == NULL) {
        printf("Could not open %s", filename);
    }

for(i=0; i<sizeof(ifp); i++) {

    fgets(site_let, AIRPORTS, ifp);

    printf("Site: %s\n", site_let);

}
    site_num = strtok(site_let,",");



    while (site_num != NULL) {

        switch(i){

        case 0:
            airport_num[j].siteNumber = malloc(sizeof(char)* 25);
            strcpy(airport_num[j].siteNumber, site_num);
                break;
        case 1:
            airport_num[j].locID = malloc(sizeof(char)* 4);
            strcpy(airport_num[j].locID, site_num);
                break;
        case 2:
            airport_num[j].fieldName = malloc(sizeof(char)* 30);
            strcpy(airport_num[j].fieldName, site_num);
                break;
        case 3:
            airport_num[j].city = malloc(sizeof(char)* 25);
            strcpy(airport_num[j].city, site_num);
                break;
        case 4:
            airport_num[j].state = malloc(sizeof(char)* 2);
            strcpy(airport_num[j].state, site_num);
                break;
  /*  case 5:
        airport_num.region = malloc(sizeof(char)* 3);
        strcpy(airport_num.region, site_num);
            break;
    case 6:
        airport_num.ado = malloc(sizeof(char)* 3);
        strcpy(airport_num.ado, site_num);
            break;
    case 7:
        airport_num.use = malloc(sizeof(char)* 2);
        strcpy(airport_num.use, site_num);
            break;*/
        case 8:
            airport_num[j].latitude = malloc(sizeof(char)* 30);
            strcpy(airport_num[j].latitude, site_num);
                break;
        case 9:
            airport_num[j].longitude = malloc(sizeof(char)* 30);
            strcpy(airport_num[j].longitude, site_num);
                break;
 /*   case 10:
        airport_num.airportOwnership = malloc(sizeof(char)* 2);
        strcpy(airport_num.airportOwnership, site_num);
            break;
    case 11:
        //left blank because of the double commas
        break;
    case 12:
        airport_num.npias = malloc(sizeof(char)* 30);
        strcpy(airport_num.npias, site_num);
            break;
    case 13:
        //left blank because of the double commas
        break;
*/
    case 14:
        airport_num[j].controlTower = site_num;
            break;
/*  case 15:
        airport_num.fuel = malloc(sizeof(char)* 6);
        strcpy(airport_num.fuel, site_num);
            break;
    case 16:
        airport_num.airCraftTotal = site_num;
            break;
*/
        default:
            break;

    }

    i++;
   site_num = strtok(NULL,",");
}

printf("sitenumber %s\n", airport_num[j].siteNumber);
printf("local id: %s\n", airport_num[j].locID);
printf("Field name: %s\n", airport_num[j].fieldName);
printf("city: %s\n", airport_num[j].city);
printf("state: %s\n", airport_num[j].state);
printf("lat: %s\n", airport_num[j].latitude);
printf("long: %s\n", airport_num[j].longitude);
printf("control tower: %c\n", airport_num[j].controlTower);

//}

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



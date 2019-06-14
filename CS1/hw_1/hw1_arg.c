//Christopher Badolato.
//2/13/2017
//COP3502 0003
//This program will run through specific input files with comma separated variables
//and print out the values that are stored there.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airPdata.h"
#define LENGTH 60
#define NUMVARS 15
#define AIRPORTS 1000



int main (int argc, char* argv[]) {
        //pointer to file
    FILE * ifp;
        //variable declaration, airports is an string of the file being read into the program.
        //airport_info is a token for each individual piece of information separated by our delimiters.
    char airports[AIRPORTS], *airport_info;
    int  i = 0, j = 0, k;
        //this is our structure declaration of type airPdata, it will store each individual piece of info for each airport. (airport_num).
    struct airPdata airport_num[LENGTH];
            //We loop through our argc to read what is typed into the command line so we can read in the file.
        for(i = 0; i<argc; i++){
            //opens our file and reads it to the input file pointer.
        ifp = fopen(argv[i], "r");
            //if some unknown file is typed in we will receive an error message
        if (ifp == NULL) {
            printf("ERROR: Could not open %s\n", argv[i]);

        }

        }
        //this line prints out our headers with appropriate spacing.
    printf("%-14s %-12s\t %-40s\t %-33s\t %-5s\t %-15s %-20s %-15s\n", "Site Number", "Local ID", "Field Name", "City", "State", "Latitude", "Longitude", "Control Tower");

        //here we loop through our file, I could not figure out an appropriate size to loop through without getting an error or segmentation fault.
        // either the file would be cut short or only the first section of input would be read in.
    for(i=0; i<=sizeof(airports); i++) {

            //fgets grabs the information from the ifp and stores it into our airport string array.
        fgets(airports, sizeof(airports), ifp);

            //if we reach the end of our file, the loop will break.
        if (feof(ifp)) {
            break;
        }
            //to go through each value of j and store the information in the specific spot we must reset j to 0 at this point in the loop.
        j = 0;
            //our token airport_info stores the information separated by our delimiter which in this case is a comma.
        airport_info = strtok(airports,",");

            //while our airport info does not equal null we will continue to add information to each structure.
        while (airport_info != NULL){
                //our first piece of info being our site number will be store in our structure array at site_number, we allocate memory for the size of the site number
                //and string copy this info from our airport_info array to the specified section of the struct. Then print out our CURRENT info.
            if( j == 0){
                airport_num->siteNumber = malloc(sizeof(char)* 30);
                strcpy(airport_num->siteNumber, airport_info);
                printf("%-10s\t", airport_num->siteNumber);
            }
                //when j = 1, the strtok will have already "eaten" the first string (string 0). it will skip to the bottom and add 1 to j.
                //this stores the next value into our struct while mallocing size in memory for the string.
            if(j == 1){
                airport_num->locID = malloc(sizeof(char)* 4);
                strcpy(airport_num->locID, airport_info);
                printf("%-5s\t", airport_num->locID);

            }
                //the processes continues on until all strings have been "eaten" by the strtok and we reach the end of the file.
                //store and print the field name.
            if(j == 2) {
                airport_num->fieldName = malloc(sizeof(char)* 40);
                strcpy(airport_num->fieldName, airport_info);
                printf("%-40s\t", airport_num->fieldName);

            }
                //store and print the city name.
            if(j == 3) {
                airport_num->city = malloc(sizeof(char)* 50);
                strcpy(airport_num->city, airport_info);
                printf("%-40s\t", airport_num->city);

            }
                //store and print the state.
            if(j == 4) {
                airport_num->state = malloc(sizeof(char)* 25);
                strcpy(airport_num->state, airport_info);
                printf("%-5s\t", airport_num->state);

            }
                //here we jump to 8, we do not need the information at the other j values for this first project.
                //store and print the latitude.
            if(j == 8) {
                airport_num->latitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->latitude, airport_info);
                printf("%-10s\t", airport_num->latitude);

            }
                //finally we store our longitude.
            if(j == 9) {
                airport_num->longitude = malloc(sizeof(char)* 30);
                strcpy(airport_num->longitude, airport_info);
                printf("%-20s\t", airport_num->longitude);

            }
                //for some reason the control tower value will not store or print "assignment makes int from pointer without cast"
                // I tried changing the char struct to a pointer and mallocing, and it made my file crash.
                //not sure what the error might be.
            if(j == 14) {
                //airport_num->controlTower = airport_info;
               // strcpy(airport_num->controlTower, airport_info);
                //printf(" %-5s", controlTower);
            }
                //breaks each at our delimiter
            airport_info = strtok(NULL,",");
                //finally adds to the j counter before returning to the top.
            j++;


        }
    printf("\t\n");
    }
        // here we free the malloc'd space in memory for each variable.
    free(airport_num->siteNumber);
    free(airport_num->locID);
    free(airport_num->fieldName);
    free(airport_num->city);
    free(airport_num->state);
    free(airport_num->latitude);
    free(airport_num->longitude);
        //finally we close our input file.
    fclose(ifp);
    return 0;
}

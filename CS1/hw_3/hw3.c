#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airPdata.h"

void parseLine(char *line, airPdata *apd);
void printData(int length, airPdata *apd);
void deleteStruct(airPdata *apd);
float sexag2decimal(char *degreeString);

#define BUFFER_SIZE 500

int main (int argc, char *argv[]){

	// Declare input buffer and other parameters
	FILE *fid;
	char buffer[BUFFER_SIZE];
	int count = 0, i;


	// Check for command line input and open input file.
	if(argc==2){
		fid = fopen(argv[1], "r");
		if(fid==NULL){
			printf("hw3Export ERROR: %s not found.\n", argv[1]);
			return 2;
		}
	}
	else{
		printf("Incorect number of input parameters. Please specify the name of the input file only.\n");
		printf("Syntax: ./hw1ecl.exe [input file]\n");
		return 1;
	}


	// Determine length of the file.
	while(fgets(buffer, BUFFER_SIZE, fid) != NULL){
		count++;
	}
	rewind(fid);


	// Declare a struct array and allocate memory.
	airPdata *data;

	data = malloc(sizeof(airPdata)*count);

	if(data==NULL){
		printf("Memory allocation for airPdata array failed. Aborting.\n");
		return 2;
	}

	// Read and parse each line of the inputt file.
	for(i = 0; i<count; i++){
		fgets(buffer, BUFFER_SIZE, fid);

		// fgets() includes the New Line delimiter in the output string.
		// i.e. "This is my string.\n\0"
		// We will truncate the string to drop the '\n' if it is there.
		// Note: There will be no '\n' if the line is longer than the buffer.
		if(buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer)-1] = '\0';

		parseLine(buffer, data+i);
	}

	// close the input file.
	fclose(fid);

	// Output the data to stdout.
	printData(count, data);

	// Free the memory used for fields of the structs.
	for(i=0; i<count; i++){
		deleteStruct(data+i);
	}

	// Free the memory for the struct array.
	free(data);

	return 0;

}


void parseLine(char *line, airPdata *apd){

	int i=0, j=0, commas=0;
	float decimal;

	while(commas<15){

		while(*(line+i)!=','){
			i++;
		}

		// strncpy does not append a '\0' to the end of the copied sub-string, so we will
		// replace the comma with '\0'.
		*(line+i) = '\0';

		switch (commas){

		case 1:   //Grab the second "field" - Location ID
			apd->LocID = malloc(sizeof(char)*(i-j+1));
			if(apd->LocID==NULL){
                        	printf("malloc failed to initialize airPdata.LocID.\n");
                                exit(-1);
                        }
                        strncpy(apd->LocID, line+j, i-j+1);
                        break;
		case 2:   //Grab the third "field" - Field Name
			apd->fieldName = malloc(sizeof(char)*(i-j+1));
			if(apd->fieldName==NULL){
				printf("malloc failed to initialize airPdata.fieldName.\n");
				exit(-1);
			}
			strncpy(apd->fieldName, line+j, i-j+1);
			break;
		case 3:   //Grab the fourth "field" - City
			apd->city = malloc(sizeof(char)*(i-j+1));
			if(apd->city==NULL){
				printf("malloc failed to initialize airPdata.city.\n");
				exit(-1);
			}
			strncpy(apd->city, line+j, i-j+1);
			break;



		case 8:
            decimal = sexag2decimal(line+j);
            apd->latitude = decimal;
			break;

		case 9:
            decimal = (sexag2decimal(line+j) * -1);
            apd->longitude = decimal;
			break;
        }
		j=++i;
		commas++;

    }
}

float sexag2decimal(char *degreeString){

    int hyphen = 0, i = 0, j = 0;
    float decimal1, decimal2, decimal3, decimal;

    if(degreeString == NULL){
        return 0.0;
    }

        while(hyphen < 3){
        while(*(degreeString+i)!='-'){
			i++;
		}

        switch (hyphen){

        case 0:
           decimal1 = atof(degreeString+j);

        case 1:
            decimal2 = atof(degreeString+j);
            decimal2 = decimal2/60;

        case 2:
            decimal3 = atof(degreeString+j);
            decimal3 = decimal3/(60*60);
        }
        hyphen++;
        j=++i;

        }
        decimal = decimal1+decimal2+decimal3;

            return decimal;

}

void printData(int length, airPdata *data){
    int i;
	printf("%s,%s,%s,%s,%s\n", "code", "name", "city", "lat", "lon");

	for(i=0; i<length; i++){
		printf("%s,%s,%s,%.4f,%.4f\n", (data+i)->LocID,(data+i)->fieldName,(data+i)->city,(data+i)->latitude,(data+i)->longitude);
	}

}

void deleteStruct(airPdata *apd){

	//free(apd->longitude);
	//free(apd->latitude);
	//free(apd->state);
	free(apd->city);
	free(apd->fieldName);
	free(apd->LocID);
	//free(apd->siteNumber);

}

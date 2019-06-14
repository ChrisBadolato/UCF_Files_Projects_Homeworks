#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Our airPdata.h has been edited with floats to store the changed strings of latitude and longitude.
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
        /*For cases 8 and 9 we no longer needed mallocs because we're storing the values as regular floats.
        we send out our current lat or lon string to sexag2decimal which separates the values, and changes it to a float.
        */
		case 8:
            decimal = sexag2decimal(line+j);
            apd->latitude = decimal;
			break;

		case 9:
                //we need our west values to be negative so we multiply our value by -1.
            decimal = (sexag2decimal(line+j) * -1);
            apd->longitude = decimal;
			break;
        }
		j=++i;
		commas++;
    }
}

/*
Christopher Badolato
COP 3502 003
04/19/2017

This function will now change a sexagesimal degree measurement into a digital degree.

This is my work, I worked by myself to develop this code, I have not copied any other person or external online source.

“Your statement that the program is entirely your own work and that you have neither developed your code together
with any another person, nor copied program code from any other person, nor permitted your code to be copied or otherwise
used by any other person, nor have you copied, modiﬁed, or otherwise used program code that you have found in any external source,
including but not limited to, online sources.”

*/

float sexag2decimal(char *degreeString){
    int hyphen = 0, i = 0, j = 0;
    float degree, minutes, milliArcSeconds, decimal;
        //if our passed in string is empty return 0.0.
    if(degreeString == NULL){
        return 0.0;
    }
        //our total number of hyphens for each latitude and longitude will always be 3.
    while(hyphen < 3){
            //we first, go through the degreeString to find the first hyphen, storing the number of characters
            //into the string we have gone.
        while(*(degreeString+i)!='-'){
			i++;
		}
            //our switch will bring us to each case as hyphen number changes, that way we reach each one
            //and break up our string correctly.
        switch (hyphen){
        case 0:
                //we take the first value, and store it as a float and leave the switch.
            degree = atof(degreeString+j);
            if(degree > 180.0 || degree < 0.0){
                return 0.0;
            }
        case 1:
                //now that our j has changed to the spot on our char array we can get our next value, change it to float, and divide by 60.
            minutes = atof(degreeString+j);
            minutes = minutes/60;
            if(minutes > 59.0 || minutes < 0.0){
                return 0.0;
            }
        case 2:
                //finally our last bit of string is changed to a float and divided by 60^2.
            milliArcSeconds = atof(degreeString+j);
            milliArcSeconds = milliArcSeconds/(60*60);
            if(milliArcSeconds > 59.9999 || milliArcSeconds < 0.0){
                return 0.0;
            }
        }
            //increment hyphen to go on to the next section of string and the next case.
        hyphen++;
            //pre-increment i and set j equal to it so we separate the correct value from the degreeString
        j=++i;
    }
        /*We then add all the values together and return them to main to be stored in our
        struct and printed with our print function.
        */
    decimal = degree+minutes+milliArcSeconds;
return decimal;
}

void printData(int length, airPdata *data){
    int i;
        //prints our strings into our file to be recognized by the maping program.
	printf("%s,%s,%s,%s,%s\n", "code", "name", "city", "lat", "lon");
        //prints our data for every airport separated by commas to store as a csv file.
	for(i=0; i<length; i++){
		printf("%s,%s,%s,%.4f,%.4f\n", (data+i)->LocID,(data+i)->fieldName,(data+i)->city,(data+i)->latitude,(data+i)->longitude);
	}
}

void deleteStruct(airPdata *apd){
        //no longer need to free lat, long, state and sitenum.
	free(apd->city);
	free(apd->fieldName);
	free(apd->LocID);
}



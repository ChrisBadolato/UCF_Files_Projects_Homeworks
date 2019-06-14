#include<stdio.h>
#include<string.h>
char* convertAndEdit(char *string);
char* countLetters(char* string);


int main(){
    char* myString = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
    char* myString2 = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
    char* lowerCase;
    char* letterCount;

    int i = 0;

    printf("%s\n", myString);

    //printf("%s", myString);
    lowerCase = convertAndEdit(myString);


    printf("\n%s", lowerCase);


    countLetters(lowerCase);

    //printf("\n \n %s", letterCount);

    return 0;
}

char* convertAndEdit(char* string){

	int counter = 0, i = 0, j = 0, asciiValue;
	char currentChar;
    char lowerCase[175];
    char letterCountArray[26][2];

	while (string[counter] != '\0')
	{
		currentChar=string[counter];
        if(isalpha(currentChar) || currentChar == ' '){

            lowerCase[i] = (char)tolower(currentChar);
            counter++;
            i++;
        }

        else{
            counter++;
        }
	}


	lowerCase[i] = '\0';
    countLetters(lowerCase);
	printf("\n%s\n", lowerCase);



    string = lowerCase;

	return string;
}

char* countLetters(char* string){

    printf("\n \n %s\n", string);
    char letterCountArray[26][2];
    char currentChar;
    int counter = 0, i, j;



	for(i =0 ; i < 26; i++){
        for(j =0; j < 2; j++){
            letterCountArray[i][0] = i + 97;
            letterCountArray[i][1] = '0';

        }
	}
    for(i =0; i < 26; i++){
        for(j =0; j < 2; j++){
            printf("%c", letterCountArray[i][j]);
        }
        printf("\n");
	}


/*
    while (string[counter] != '\0')
	{
		currentChar=string[counter];
		counter++;
	}*/
    return string;

}





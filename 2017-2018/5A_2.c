
int main(){
    char* myString = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
    char* myString2 = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
    char* letterCount;
    char currentChar;
    char lowerCase[175];
    char wordCountString[175];


    int wordCountTable[8][2];

    int currentCharInt, wordCountInt = 0;
    int i = 0, counter = 0, j = 0;

    char letterCountArray[26][2];

    printf("%s \n", myString);
        //loop through the string with a while loo

    while (myString[counter] != '\0')
	{
		currentChar=myString[counter];
        if(isalpha(currentChar) || currentChar == ' '){

            lowerCase[i] = (char)tolower(currentChar);
            wordCountString[i] = (char)tolower(currentChar);
            counter++;
            i++;
        }

        else{
            counter++;
        }
	}

	lowerCase[i] = 0;
    wordCountString[i] = 0;

	printf("\n%s\n", wordCountString);
    printf("\n%s\n", lowerCase);

    counter = 0;
	for(i =0 ; i < 26; i++){
        for(j =0; j < 2; j++){
            letterCountArray[i][0] = i + 97;
            letterCountArray[i][1] = '0';

        }
	}

        //figured I would also try to loop through a string with a for loop.
        //This loop will check if the current character in the alphabet. If it is
        //we will figure out the integer value for that character and then,
        //increment at that character the number of times we've seen that character.
	for (i = 0; lowerCase[i] != '\0'; i++){
        currentChar = lowerCase[i];
        if(isalpha(currentChar)){
            currentCharInt = currentChar - 'a';
            letterCountArray[currentCharInt][1]++;
        }
    }

    printf("\n");

    for(i =0; i < 26; i++){
        for(j =0; j < 2; j++){
            printf(" %c", letterCountArray[i][j]);
        }
        printf("\n");
	}

    printf("\n%s\n", lowerCase);

    for(i =0; i < 9; i++){
        for(j =0; j < 2; j++){
            wordCountTable[i][0] = i;
            wordCountTable[i][1] = 0;
        }

	}

	while (myString[counter] != '\0'){
		currentChar = myString[counter];
        if(currentChar == ' '){
            wordCountTable[wordCountInt][1]++;
            wordCountInt = 0;
        }
        else{
            wordCountInt++;
        }
        counter++;
	}
    wordCountTable[wordCountInt][1]++;

    printf(" \n");
    for(i = 0; i < 9; i++){
        for(j =0; j < 2; j++){
             printf("%d ", wordCountTable[i][j]);
        }
         printf("\n");
	}


    return 0;
}

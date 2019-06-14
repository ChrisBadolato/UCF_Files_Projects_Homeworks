//Christopher Badolato CH432391
//Assignment 4A
//10/10/2018
//ENC3211

//This program will calculate standard deviation, adjusted the exam scores
//based on the deviation, then sort the exam scores

#include <stdio.h>
#include <math.h>

int main() {
        //loops and temp values
        //we need a few arrays for this assignment, our existing array
        //a copy to sort, one to hold the sums of our deviations, and one for
        //our adjusted exam scores, also our final sorted adjusted scores.
        //along with all of our float variables needed.
    int examScores[] = {80, 82, 90, 95, 90, 87, 92};
    int sortedArray[] = {80, 82, 90, 95, 90, 87, 92};
    float valuesMinusAvergeSquared[7];
    float adjustedExamScores[7];
    float sortedAdjustedExamScores[7];

    int i, j, temp;
    float standardDeviation, average, sumOfValues = 0, sumOfValuesMinusAverageSquared;
    float valueUnderRoot, oneSeventh;
        //print our exam scores
    printf("Exam Scores: ");
    for(i = 0; i < 7; i++){
        printf(" %d", examScores[i]);
    }
        //first step of finding standard deviation is to find the average;
    printf("\n");
    printf("\n");
    for(i = 0; i < 7; i++){
        valuesMinusAvergeSquared[i] = 0;
        sumOfValues = sumOfValues + examScores[i];
    }
    average = sumOfValues/7;
        //after we find the average we need to subtract each value from
        //the average and square them and sum them all together.
    for(i = 0; i < 7; i++){
        valuesMinusAvergeSquared[i] = pow((float)examScores[i] - average, 2);
        sumOfValuesMinusAverageSquared = sumOfValuesMinusAverageSquared + valuesMinusAvergeSquared[i];
    }
        //get the final value underneath the root by multiplying by n (7)
        //then take square root to get the std deviation.
    valueUnderRoot = sumOfValuesMinusAverageSquared/7;
    standardDeviation = sqrt(valueUnderRoot);
    printf("Standard deviation: %.04f\n", standardDeviation);
    printf("\n");
        //Here we will adjust the exams scores by the standard deviation then
        //print the list back out.

    printf("Adjusted exam scores: ");
    for(i = 0; i < 7; i++){
        adjustedExamScores[i] = examScores[i] + standardDeviation;
        printf(" %.0f", adjustedExamScores[i]);
    }
    printf("\n");
    printf("\n");
        /*
        To sort we much start by going through each number at least once
        we will go through again starting at our first term checking to
        see if it is greater than the value next to it.
        if it is, swap the values on the list.

        To make sure the last elements are already in place
        on the inside loop we subtract i from the length of the array.
        therefore each pass it makes one less comparison and we can print
        as we get those values.
        */
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7-i-1; j++)
           if (sortedArray[j] > sortedArray[j+1]){
                temp = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = temp;
            }
    }
    printf("Sorted exam scores: ");
        //finally we adjust the sorted scores
        //and reprint the adjusted list.
    for(i = 0; i < 7; i++){
        sortedAdjustedExamScores[i] = sortedArray[i] + standardDeviation;
        printf(" %.0f", sortedAdjustedExamScores[i]);
    }
    printf("\n");
    return 0;
}




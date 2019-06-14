//template
//
//
//

#include <stdio.h>


int main() {
    //declare variables
    int grade1 = 75;
    int grade2 = 80;

    //calculate the averages
    int average1 = (grade1 + grade2)/2;
    int average2 = grade1 + grade2/2;
    int average3 = grade2 + grade1/2;
    double average4 = (grade1+grade2)/2;
    double average5 = (double)(grade1+grade2)/2;
    double average6 = (grade1+grade2)/2.0;
    double average7 = (double)((grade1+grade2)/2);

    printf("Ave = #1 = %d\n", average1);
    printf("Ave = #2 = %d\n", average2);
    printf("Ave = #3 = %d\n", average3);
    printf("Ave = #4 = %1lf\n", average4);
    printf("Ave = #5 = %1lf\n", average5);
    printf("Ave = #6 = %1lf\n", average6);
    printf("Ave = #7 = %1lf\n", average7);


    system("pause");
return 0;
}

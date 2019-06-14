//template
//
//
//

#include <stdio.h>
#include <math.h>


int main() {
    double x1, y1, x2, y2;

    printf("Enter the coordinates of the first point.\n");
    scanf("%lf%lf", &x1, &y1);

    printf("Enter the coordinates of the second point.\n");
    scanf("%lf%lf", &x2, &y2);

    //calculate the distance

    double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

    printf("The distance between (%lf,%lf) and ", x1, y1);
    printf("(%lf,%lf) is %lf.\n", x2, y2, dist);

    system("pause");
return 0;
}

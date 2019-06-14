#include <stdio.h>

union floatingPoint{
	float f;
	double d;
	long double l;
};

int main(void)
{
	union floatingPoint unionValue;

	printf("Enter data for type float: ");
	scanf("%f", &unionValue.f);

    printf("\nBreak down of elements in the union\n");
	printf("float %f\n", unionValue.f);
	printf("double %lf\n", unionValue.d);
	printf("long double %lf\n", unionValue.l);

	printf("\nBreak down in hex\n");
    printf("float %x\n", unionValue.f);
	printf("double %x\n", unionValue.d);
	printf("long double %x\n", unionValue.l);

	printf("\nEnter data for type double: ");
	scanf("%lf", &unionValue.d);

    printf("\nBreak down of elements in the union\n");
	printf("float %f\n", unionValue.f);
	printf("double %lf\n", unionValue.d);
	printf("long double %Lf\n", unionValue.l);

	printf("\nBreak down in hex\n");
    printf("float %x\n", unionValue.f);
	printf("double %x\n", unionValue.d);
	printf("long double %x\n", unionValue.l);

	printf("\nEnter data for type long double: ");
	scanf("%Lf", &unionValue.l);

    printf("\nBreak down of elements in the union\n");
	printf("float %f\n", unionValue.f);
	printf("double %lf\n", unionValue.d);
	printf("long double %Lf\n", unionValue.l);

	printf("\nBreak down in hex\n");
    printf("float %x\n", unionValue.f);
	printf("double %x\n", unionValue.d);
	printf("long double %x\n", unionValue.l);

	return 0;
}

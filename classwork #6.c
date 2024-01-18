#include<stdio.h>

void area(float *ptr);


int main()
{
    float rad;

    printf("Enter in the radius of the circle: ");
    scanf("%f", &rad);

    area(&rad);

    return 0;
}

void area(float *ptr)
{
    float pi = 3.14;
    float area = (*ptr) * (*ptr) * pi;
    printf("\nArea of circle is %f", area);
}

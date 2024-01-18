#include<stdio.h>

double RecArea(double l, double w);
double TriArea(double h, double b);

int main()
{
    double l;
    double w;

    printf("Enter the length of the rectangle here: ");
    scanf("%lf", &l);

    printf("Enter the width of the rectangle here: ");
    scanf("%lf", &w);

    double p1 = RecArea(l, w);

    printf("\n");

    double h;
    double b;

    printf("Enter the height of the triangle here: ");
    scanf("%lf", &h);

    printf("Enter the base of the triangle here: ");
    scanf("%lf", &b);

    double p2 = TriArea(h, b);

    // sum
    double sum = 0;
    sum = p1 + p2;
    printf("\n");
    printf("The sum of those two areas is %lf. \n", sum);

    // greater
    if (p2 > p1)
    {
        printf("Area of the triangle is greater than the area of the rectangle.\n");
    }
    else if (p1 > p2)
    {
        printf("Area of the rectangle is greater than the area of the triangle.\n");
    }
    else if (p2 == p1)
    {
         printf("The areas are equal.\n");
    }
    return 0;
}

double RecArea(double l, double w)
{
    double Area = l * w;
    printf("The area of the rectangle is %lf. \n", Area);
    return Area;
}

double TriArea(double h, double b)
{
    double Area = (h * b) / 2;
    printf("The area of the triangle is %lf. \n", Area);
    return Area;
}



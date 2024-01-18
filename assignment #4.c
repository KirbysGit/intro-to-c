#include<stdio.h>

int main()
{
	// Problem #1
    int x = 2;
	for (x = 2; x <= 20; x++)
	{
	    if (x % 2 == 0)
        {
            if ((x == 12) || (x == 16))
                continue;
            else
                printf("%d\n", x);
        }
	}
    printf("\n");

	// Problem #2

	int input;
	int count = 0;
	int sum = 0;
	int i;
    int s;
	printf("Please enter a number: ");
	scanf("%d", &input);
	printf("\n");
	for (i = 1; i <= input; i++)
    {
        if (i % 2 == 1)
        {
            count++;
            sum = sum + i;
        }
    }
    printf("Number of Odd numbers between 1 and 7 is: %d\n", count);
    printf("\n");
    printf("Sum of Odd numbers between 1 and 7 is: %d\n", sum);
    printf("\n");
    for (s = 0; s < sum; s++)
        printf("*");

    printf("\n");
    printf("\n");

    // Problem #3

    double base;
    double exponent;
    double product;

    printf("Please enter a base value: ");
    scanf("%lf", &base);
    printf("Please enter a exponent value: ");
    scanf("%lf", &exponent);

    product = pow(base, exponent);

    printf("\n");
    printf("Value: %.2lf", product);




    return 0;
}

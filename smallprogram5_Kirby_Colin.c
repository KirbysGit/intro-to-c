#include<stdio.h>
#include<math.h>

void change(double *paid, double *due); //func prototypes
void multTable(int *rows, int *columns);
void minimum(int *num1, int *num2);
void incrementUpdate(int *val);

int main()
{
	//Problem #1
	double ps, ds; //declaration
	printf("Amount Due: "); //scanf statements to obtain values
	scanf("%lf", &ds);
	printf("Amount Paid: ");
	scanf("%lf", &ps);
	double *due = &ds; //sets pointer = to address value
	double *paid = &ps;
	change(&ps, &ds); //calls back function change
	
	//Problem #2
	int rs, cs; //declaration
	printf("Enter number of rows: "); //scanf statements to obtain values
	scanf("%d", &rs);
	printf("Enter number of columns: ");
	scanf("%d", &cs);
	int *rows = &rs; //sets pointer = to address value
	int *columns = &cs;
	multTable(&rs, &cs); //calls back function multTable
	
	//Problem #3
	int n1, n2; //declaration
	printf("Enter num1: "); //scanf statements to obtain values
	scanf("%d", &n1);
	printf("Enter num2: ");
	scanf("%d", &n2);
	int *num1 = &n1; //sets pointers = to address value
	int *num2 = &n2;
	minimum(&n1, &n2); //calls back function minimum
	
	//Problem #4
	int option = 0; //declaration statements
	int v = 0;
	printf("Before calling incrementUpdate\n"); //before loop print statments
	printf("val = %d\n", v);
	while (option == 0) //while the option is 0 it will loop
	{
		printf("Updating val now...\n"); //in loop print statements
		printf("Would you like to update ...\n");
		printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");
		printf("Option: ");
		scanf("%d", &option); //scanf statement for value
		int *val = &v; //sets pointer = to value
		incrementUpdate(&v); //calls back function incrementUpdate mid loop
	}
	printf("val is now done updating...\n"); //after loop ends print statements
	printf("After calling incrementUpdate\n");
	printf("val = %d \n", v);
	return 0;
}

void change(double *paid, double *due)
{
	double amount; //declaration statements
	double x = 0.0000025; //value for rounding erros
	amount = *paid - *due; //solves for amount through subtraction of pojnters
	int dollars = 0; //more declaration statements to prevent other errors
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	if (amount >= 1) //if amount is more than 1 ->
	{
		dollars = floor(amount); // -> the dollars now equal to amount rounded to nearest int
		amount = amount - dollars; //solves for new amount 
	}
	if (amount >= 0.25)//if amount is more than 0.25 ->
	{
		quarters = amount * 4; // -> solves for amount of quarters then
		quarters = floor(quarters); // -> floors the amount to get whole number
		amount = amount - (0.25 * quarters) + x; // solves for new amount
	} 
	if (amount >= 0.10)//if amount is more than 0.10 ->
	{
		dimes = amount * 10; //-> solves for whole number of dimes
		amount = amount - (dimes * 0.10) + x; //solves for new amount
	}
	if (amount >= 0.05)//if amount is more than 0.05
	{
		nickels = amount * 20; // solves for whole number of nickels
		amount = amount - (nickels * 0.05) + x; //solves for new amount
	}
	if (amount >= 0.01) //if amount is more than 0.01 
	{
		pennies = amount * 100; //solves for whole number of pennies
		amount = amount - (pennies * 0.01) + x; //solves for new amount which should be zero or very close to it
	}
	printf("Change\n"); //print statements
	printf("%d dollars\n", dollars);
	printf("%d quarters\n", quarters);
	printf("%d dimes\n", dimes);
	printf("%d nickels\n", nickels);
	printf("%d pennies\n", pennies);
}

void multTable(int *rows, int *columns)
{
	int i, j; //declaration
	for (i = 1; i <= *rows ; i++) //nested for loops to get increasing values
	{
		for (j = 1; j <= *columns; j++) 
		{
			if (j * i < 10) //if-else statements for proper spacing
				printf("      %d", j * i);
			else
				printf("     %d", j * i);
		}
		printf("\n");
	}
}

void minimum(int *num1, int *num2)
{
	if (*num1 > *num2) //simple if else statement using the pointers
		printf("%d is smaller than %d.\n", *num2, *num1);
	else if(*num2 > *num1)
		printf("%d is smaller than %d.\n", *num1, *num2);
}

void incrementUpdate(int *val)
{
	*val = *val + 1; //just solves for the val at end of loop 
}
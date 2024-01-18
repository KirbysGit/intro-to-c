//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
// Small Program 1 

#include<stdio.h>

int main()
{
	//Problem #1: Printing YY in shape of YY
	printf("YY        YY\n");
	printf(" YY      YY\n");
	printf("  YY    YY\n");
	printf("   YY  YY\n");
	printf("     YY\n");
	printf("     YY\n");
	printf("     YY\n");
	printf("     YY\n");
	printf("     YY\n");
	
	double BOR; //declaration of multiple variables
	double EOR;
	double t;
	double re;
	printf("Mileage Reimbursement Calculator\n"); 
	printf("Enter beginning odometer reading=> ");
	scanf("%lf", &BOR); //accepting the inputted value and saving it in the ram as BOR
	printf("Enter ending odometer reading=> ");
	scanf("%lf", &EOR); //accepting the inputted value and saving it in the ram as EOR
	t = (EOR - BOR); //setting the variable t as EOR - BOR
	printf("You traveled %.1lf miles.\n", t); //printing t rounded to 1 decimal
	re = (t * 0.35); //multiplying the variable t by the value 0.35 to get the reimbursement
	printf("At $0.35 per mile, your reimbursement is $%.2lf\n", re); //print re to 2 decimals
	
	double weight; //declarations
	double height;
	double BMI;
	printf("Enter the weight in pounds: ");
	scanf("%lf", &weight); //accepting the user inputted value and setting it as weight
	printf("Enter the total height in inches: ");
	scanf("%lf", &height); //accepting the user inputted value and setting it as height
	BMI = (weight * 703)/(height * height); //setting BMI = to the inputted weight multiplied by 703 divided by height squared
	printf("BMI = %.3lf\n", BMI); //printing the variable BMI to three decimal points
	
	double r; //declarations
	double h;
	double p;
	double V;
	p = 3.14159; //setting p equal to 3.14159 aka pi for the equation later on
	printf("Enter the radius: ");
	scanf("%lf", &r); //accepting the user inputted value and saving it as r 
	printf("Enter the height: ");
	scanf("%lf", &h); // accepting the user inputted value and saving it to the ram as h
	V = (p * r * r * h)/3; //setting up the equation for a cone as pi*r^2*h all divided by 3 and setting it equal to V
	printf("The volume of the cone is %.4lf\n", V); //printing the volume of the cone to 4 decimal places
	
	
	return 0;
	
}


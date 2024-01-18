//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 2 

#include<stdio.h> // Calls library
#include<math.h>

double coneSurfaceArea(double p, double r, double h); //Prototypes for functions
double parkingCharge(int hours, double rate);
void halaPopulation(int year);
double factorialApprox(int num);

int main()
{
	double r; //Problem #1: 
	double h; // Declaration statements
	double p;
	p = 3.14;
	printf("Enter the radius: "); // Request input from user for radius and height
	scanf("%lf", &r); // Saves variable by name
	printf("Enter the height: ");
	scanf("%lf", &h);
	coneSurfaceArea(p, r, h); // Calls back coneSurfaceArea function
	
	
	int hours; //Problem #2
	double rate; //Declaration statements
	rate = 1.73; 
	printf("Welcome to the Parking Garage!\n"); //Print statement
	printf("How many hours will you keep your car parked here> "); //Request input for hours
	scanf("%d", &hours); // Saves variable by name
	parkingCharge(hours, rate); // Calls back parkingCharge function
	
	int tyear; //Problem #3
	int year; // Declaration statements
	printf("Enter a year after 1990: "); //Request input for a year after 2022 
	scanf("%d", &tyear); // Saves variable by name
	year = tyear - 1990; // Solves for proper year to use equation
	halaPopulation(year); // Calls back halaPopulation() function
	
	int num; //Problem #4
	printf("Enter the value for n: "); //Request input for value for n
	scanf("%d", &num); //Saves variable by name
	factorialApprox(num); // Calls back factorialApprox() function
	
	return 0;
}

double coneSurfaceArea(double p, double r,double h)
{
	double TSA = p * r * (r + sqrt((h * h) + (r * r))); // Declares TSA as the total surface area equation
	printf("The total surface area of the cone is %.2lf\n",TSA); // Displays total surface area to 2 decimal places
}

double parkingCharge(int hours, double rate)
{
	double charge = (hours * rate); // Declares charge as hours times rate 
	printf("Car will be parked for %d hours and will be charged $%.2lf.\n", hours, charge); // Displays hours and charge to two decimal places
}

void halaPopulation(int year)
{
	double c = 60.236; // Declares constants to simplify my equation
	double poprate = 2.247;
	double pop = c + (poprate * year); // Declares pop equal to equation for population growth
	printf("Predicted Hala's population for 2022 (in thousands): %.3lf\n", pop); // Displays predicted population to three decimals
}

double factorialApprox(int num)
{	
	double result = (pow(num,num))*(exp(-num))*(sqrt((((2.0 * (num)) + (1.0/3.0)))*(3.14))); // Declares result equal to equation for factorial
	printf("%d! is approximately %.4lf\n", num, result); // Displays factorial to 4 decimals places
}
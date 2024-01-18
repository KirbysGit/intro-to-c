//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 2 
#include<stdio.h>
#include<ctype.h>

void letters(void); //Function prototypes
void operator(int option);
void coordinates(double x, double y);
int triangle(int a, int b, int c);


int main() //Declares main function
{
	//Problem #1
	letters(); //Calls back the function letters
	
	//Problem #2
	int option; //Declaration statement
	operator(option); //Calls back operator function with parameters of option
	
	//Problem #3
	double x; //Declaration statements
	double y;
	printf("Enter the x-coordinate: "); //Input statements with scanf statements to address variables
	scanf("%lf",&x);
	printf("Enter the y-coordinate: ");
	scanf("%lf",&y);
	coordinates(x,y); //Calls back function coordinates with parameters of variable x and y
	
	//Problem #4
	int a; //Declaration statements
	int b;
	int c;
	printf("Enter three sides separated by a whitespace: "); //Input statements for user
	scanf("%d %d %d", &a, &b, &c);//Scanf statemetns to address value
	if (triangle(a, b, c) == 1) //If-else statemetes based on function triangle returning 1 or -1
		printf("Triangle!\n");
	else
		printf("Not Triangle!\n");
	
	
	
	
	return 0;
}

void letters() 
{
	char letter; //declaration statement
	printf("Enter a key from the keyboard: "); //input statements
	scanf("%c",&letter);
	if (isalpha(letter))//if-else statements to determine if character is a letter then to see if letter is upper or lower case
	{
		if (islower(letter))
			printf("Lower!\n");
		else if(isupper(letter))
			printf("Upper!\n");
	}
	else
		printf("Not a Letter!\n"); //prints statement if inputted character is letter
}

void operator(int option)
{
	printf("Welcome to Super Duper Company Services Phoneline!\n"); //Bunch of print statements
	printf("Please listen carefully to the options of who you would like to speak to.\n");
	printf("Option 1: Accounting Department\n");
	printf("Option 2: Sales Department\n");
	printf("Option 3: Customer Services\n");
	printf("Option 4: Executive Department\n");
	printf("Option 5: Next Available Representative\n");
	printf("Selection: "); //Input statement
	scanf("%d",&option);
	if(option == 1) // If-else statements based on user inputted integer 
		printf("You have asked for the Accounting Department! Transferring Now!\n");
	else if(option == 2)
		printf("You have asked for the Sales Department! Transferring Now!\n");
	else if(option == 3)
		printf("You have asked for Customer Services! Transferring Now!\n");
	else if(option == 4)
		printf("You have asked for the Executive Department! Transferring Now!\n");
	else if(option == 5)
		printf("You have asked to speak to the next available representative! Please hold!\n");
	else
		printf("I'm sorry. I don't recognize that option.\n");
}

void coordinates(double x, double y)
{
	if (x > 0) //Nested If-else statements based on user inputted values printing the coordinates and which quadrant each lay
	{
		if (y > 0)
			printf("(%.2lf, %.2lf) is in quadrant I.\n", x, y);
		else if (y < 0)
			printf("(%.2lf, %.2lf) is in quadrant IV.\n", x, y);
		else if (y == 0)
			printf("(%.2lf, %.2lf) is on the x-axis.\n", x, y);
	}
	else if (x < 0)
	{
		if (y > 0)
			printf("(%.2lf, %.2lf) is in quadrant II.\n", x, y);
		else if (y < 0)
			printf("(%.2lf, %.2lf) is in quadrant III.\n", x, y);
		else if (y == 0)
			printf("(%.2lf, %.2lf) is on the x-axis.\n", x, y);
	}
	else if (x == 0)
	{
		if (y > 0)
			printf("(%.2lf, %.2lf) is on the y-axis.\n", x , y);
		else if (y < 0)
			printf("(%.2lf, %.2lf) is on the y-axis.\n", x, y);
		else if (y == 0)
			printf("(%.2lf, %.2lf) is at the origin.\n", x, y);
	}
}

int triangle(int a, int b, int c)
{
	printf("Checking these logistics from the input.\n"); //Print statements to display what the statement is checking
	printf("%d + %d > %d\n", a, b, c);
	printf("%d + %d > %d\n", a, c, b);
	printf("%d + %d > %d\n", b, c, a);
	
	if ((a + b) > c)//Simplified if statement to return value of 1 or -1 to be used in if else statments in main function
		
		
		
	return 1;

}
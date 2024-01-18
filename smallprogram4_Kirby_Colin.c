//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 4

#include<stdio.h>

void pattern(); // Function prototypes.
void elevator();
int fibonacci(int n);
void boardPattern(int total);


int main()
{
	//Prob #1
	pattern(); //Callback for function pattern
	
	//Prob #2
	elevator(); //Callback for function elevator
	
	//Prob #3
	int val; // Declaration statements
	int n = 0;
	while(n <= 1) // While loop based on invalid inputs
	{
			printf("Enter a number: "); // Prompts user for input
			scanf("%d", &n);
			if (n >= 1) //If inputted value is > 1 then ends loop
				break;
			else //Else the loop continues until proper value is inputted
				printf("Invalid Input. Please try again.\n");
	}
	
	val = fibonacci(n); //Callback of function fibonacci and set value equal to val
	printf("F(%d) = %d\n", n, val); //Print statements for val
	
	//Problem #4
	int total = -1; //Set equal to -1 so while loop works
	while(total <= 0) // While loop based on invalid inputs
	{
		printf("Enter number of rows: ");
		scanf("%d", &total);
		if (total >= 0) // If total is a proper value then loop ends
			break;
		else // Else loop continues
			printf("Invalid Input. Please try again.\n");
	}
	boardPattern(total); //Calls back function boardpattern
	
	
	
	return 0;
}

void pattern()
{
	int st1; //Declaration
	int st2;
	int steps = 0;
	while(steps < 1) //While loop based on invalid input
	{
		printf("How many steps would you like in the pyramid? "); //Prompts user for input
		scanf("%d", &steps);
		if(steps > 0)
			break;
		else
			printf("Invalid Input. Please try again.\n");
	}
	for (st1 = 1; st1 < steps; st1++) //Begins by incrementing st1 up by 1 while st1 < steps
	{
		for(st2 = 0; st2 < st1; st2++) // Then while st1 is being incremented st2 begins incrementing until st1 = steps and thus st2 = st1
		{
				printf("-"); //The printed char for the pyramid
		}
		printf("\n");
	}
	for (st1 = 0; st1 < steps; st1++) //Begins by incrementing st1 up by 1 while st1 < steps
	{
		for(st2 = steps; st2 > st1; st2--) // Opposite of the previous function while st2 > st1 it decreases until st1 = st2
		{
				printf("-");
		}
		printf("\n");
	}

}

void elevator()
{
	printf("Welcome to the Elevator Ride.\n");
	int floor = 0; //Declaration
	while(floor != 8) //While floor is not 8 it will print the provided statements depending on inputted value
	{
		printf("Which floor would you like to go to? "); // Prompts user for input
		scanf("%d", &floor);
		if (floor == 1) // Series of if-else statements revolved around the user inputted value and printing a specific output based on that value
			printf("Welcome to the first floor.\n");
		else if(floor == 2)
			printf("Welcome to the second floor.\n");
		else if(floor == 3)
			printf("Welcome to the third floor.\n");
		else if(floor == 4)
			printf("Welcome to the fourth floor.\n");
		else if(floor == 5)
			printf("Welcome to the fifth floor.\n");
		else if(floor == 6)
			printf("Welcome to the sixth floor.\n");
		else if(floor == 7)
			printf("Welcome to the seventh floor.\n");
		else if(floor == 8)
			;
		else 
			printf("That is not a valid option.\n");
	}
	printf("Elevator door is now open. Please exit.\n"); // After loop ends (floor == 8) then prints this statement
}

int fibonacci(int n)
{
	int F0 = 0; // Declaration statements
	int F1 = 1;
	int Fn; 
	int x;
	
	for(x = 2; x <= n; x++) //For loop beginning at 2 so while 2 <= n it will increment and continue to repeat the provided equations
	{
		Fn = F0 + F1; //Act as the beginning equation yet after completely first calculation it will change the two values until x == n
		F0 = F1;
		F1 = Fn;
	}
	return Fn; // Following loop break (when n == x) it will return value Fn
		
}

void boardPattern(int total)
{
	int i, j, k; //Declarations 
	for (i = 1; i <= total; i++) //Nested for loops
	{
		for (j = i; j <= i; j++)//As i increments towards total and j increments towards i the if else statements determine what to print
		{
			if (j % 2 != 0) //If remainder of j / 2 doesnt = 0 it will print the statement below
				printf(" + + + + + + + + + +\n");
			else if (j % 2 == 0) //Else the remainder of j/2 does = 0 it will print statement below
				printf("+ + + + + + + + + +\n");
		}
	}
}



		



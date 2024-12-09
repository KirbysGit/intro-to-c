//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Large Program 2

#include<stdio.h>
#include<ctype.h>

void greeting(); //provided prototypes
void order(double *balance);
void viewAccount(double *balance);
void transaction(double *balance, double price);
void reload(double *balance);
void displayMenu();

int main()
{
	char answer = 'a'; //declarations
	char option;
	double money;
	double *balance = &money;
	greeting();
	while (answer != 'e') //while loop to display options while input doesnt = 'e'
	{
		printf("Please select one of the following options.\n"); //print statements
		printf("O: Order\n");
		printf("V: View Account Summary\n");
		printf("D: Display Menu\n");
		printf("R: Reload Account\n");
		printf("E: Exit\n");
		printf("****************************************************\n");
		printf("Please select what you would like to do.\n");
		printf("Option selected: "); //accepts input
		scanf(" %c", &option); //sets address
		printf("\n");
		answer = tolower(option); //makes it so any input is lower case
		if (answer == 'v')
		{
			printf("You selected the View Account Summary Option\n"); //print statements
			printf("****************************************************\n");
			viewAccount(&money); //calls back viewAccount function
		}
		else if(answer == 'd')
		{
			printf("You selected Display Menu Option.\n"); //print statements
			printf("****************************************************\n");
			displayMenu(); //calls back displayMenu function
		}
		else if(answer == 'o')
		{
			printf("You have selected the Order option.\n");
			displayMenu(); //calls back displayMenu function
			order(balance); //calls back order function
		}
		else if(answer == 'r')
		{
			printf("You selected the Reload Account option\n");
			printf("****************************************************\n");
			reload(balance); //calls back reload function
		}
		else if(answer == 'e')
			break; //prevents else statement to be printed when e is inputted
		else
			printf("Please select one of the provided characters.\n"); //if input is incorrect then print
	}
	
	printf("Thank you for visiting Knightro's Coffee Shop!\n"); //final print statements
	printf("You have $%.2lf in your account.\n", *balance);
	printf("Have a great day!\n");
	printf("Go Knights! Charge On!\n");
	return 0;        
}

void greeting()
{
	printf("Welcome to the Knighttro's Coffee Shop!\n"); //print statements
	printf("We serve delicious coffee and snacks!\n");
	printf("How can we help you today?\n");
	printf("****************************************************\n");
}

void viewAccount(double *balance)
{ 
	printf("Here is your current account balance.\n"); // print statements 
	printf("You have $%.2lf in your account.\n", *balance);
	printf("****************************************************\n");
}

void order(double *balance)
{
	int choice; //declarations
	double price;
	printf("What would you like today?\n"); //prints
	printf("Option Selected: "); //accepts input
	scanf("%d", &choice);
	printf("\n");
	if (choice == 1) //based off input outputs certain print statement and sets price = to certain amount
	{
		printf("Hot Coffee has been selected. Total cost is: $3.53\n");
		price = 3.53;
	}
	else if(choice == 2)
	{
		printf("Ice Coffee has been selected. Total cost is: $4.20\n");
		price = 4.20;
	}
	else if(choice == 3)
	{
		printf("Hot Latte has been selected. Total cost is:  $3.13\n");
		price = 3.13;
	}
	else if(choice == 4)
	{
		printf("Iced Latte has been selected. Total cost is: $4.12\n");
		price = 4.12;
	}
	else if(choice == 5)
	{
		printf("Bagel has been selected. Total cost is: $3.99\n");
		price = 3.99;
	}
	else if(choice == 6)
	{
		printf("Big Scone has been selected. Total cost is: $4.99\n");
		price = 4.99;
	}
	else if(choice == 7)
	{
		printf("Frozen Coffee has been selected. Total cost is: $5.03\n");
		price = 5.03;
	}
	else if(choice == 8)
	{
		printf("Bottle Water has been selected. Total cost is: $1.50\n");
		price = 1.50;
	}
	else
		printf("Sorry that option is not on the menu! Please select again!\n");
	
	transaction(balance, price); //calls back transaction function
	
}

void displayMenu()
{
	printf("Here are the options!\n"); //print statements
	printf("****************************************************\n");
	printf("1. Hot Coffee				$3.53\n");
	printf("2. Iced Coffee				$4.20\n");
	printf("3. Hot Latte				$3.13\n");
	printf("4. Iced Latte 				$4.12\n");
	printf("5. Bagel (includes cream cheese)        $3.99\n");
	printf("6. Big Scone				$4.99\n");
	printf("7. Frozen Coffee			$5.03\n");
	printf("8. Bottle Water				$1.50\n");
	printf("****************************************************\n");
}

void transaction(double *balance, double price)
{
	printf("Beginning Transaction Process.\n");
	if (*balance < price) //if users balance is less than price
	{
		while (*balance <= price) //the while loop will run making them input a certain amount of cash until balance > price
		{
			printf("You do not have enough in your account.\n");
			printf("Please reload your account balance.\n");
			printf("****************************************************\n");
			reload(balance); //calls back reload function
		}
		printf("Your account balance before official transaction: $%.2f\n", *balance); //prints balance
		printf("Billing %.2f to your account.\n", price); //prints price of item
		printf("Transaction was successful!\n");
		printf("You have now $%.2f in your account balance.\n", *balance - price); //prints new balance
		printf("****************************************************\n");
		*balance = *balance - price; //saves new balance
	}
	else if(*balance >= price) //if balance is greater than price
	{
		printf("Your account balance before official transaction: $%.2f\n", *balance); //prints balance
		printf("Billing %.2f to your account.\n", price); //prints price of item
		printf("Transaction was successful!\n");
		printf("You have now $%.2f in your account balance.\n", *balance - price); //prints new balance
		printf("****************************************************\n");
		*balance = *balance - price; //saves new balance
	}
}

void reload(double *balance)
{
	int amount; //declaration
	printf("How much would like reload to your account.\n"); //print statements
	printf("1: $1.00\n");
	printf("2: $5.00\n");
	printf("3. $10.00\n");
	printf("Option Selected: ");
	scanf("%d", &amount); //accepts user inputer
	printf("****************************************************\n");
	if (amount == 1) //if user inputs 1 then
	{
		*balance = *balance + 1; // 1 is added to account
		printf("$1.00 has been added to your account successfully!\n");
		printf("****************************************************\n");
	}
	else if (amount == 2)//if user inputs 2 then
	{
		*balance = *balance + 5; // 5 is added to account
		printf("$5.00 has been added to your account successfully!\n");
		printf("****************************************************\n");
	}
	else if (amount == 3)//if user inputs 3 then
	{
		*balance = *balance + 10; // 10 is added to account
		printf("$10.00 has been added to your account successfully!\n");
		printf("****************************************************\n");
	}
	else // makes user enter correct option
		printf("Sorry that is not an option. Please select again.\n");
	
}
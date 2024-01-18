//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Large Program 4

#include<stdio.h> //libraries
#include<string.h>
#include<ctype.h>

#define SIZE 30 //definition


//original typedef struct
typedef struct{
	int Rank;
	char FirstName[SIZE];
	char LastName[SIZE];
	int Height;
	double PPG;
} player;

//prototypes

void intro(); //prints intro statements
void hardcode(player p1[SIZE]); //hardcodes values into 7 structs
void options(); //prints option statements
void display(player p1[SIZE], int n); //prints all records with typedef of struct
void insert(player p1[SIZE], int n); //allows user to insert own record
int Remove(player p1[SIZE], int n); //allows user to remove record
void Search(player p1[SIZE], int n); //allows user to search through records based on certain filter




int main()
{
	player p1[SIZE]; //declarations
	char choice;
	char input = 'o'; 
	int n = 7;
	
	intro();
	options(); //calls func
	hardcode(p1); //calls func
	while (input != 'e')
	{
		printf("------------------------------------------\n");
		printf("Enter the letter choice here: "); //request input
		scanf(" %c",&choice);
		input = tolower(choice); //sets lower case input = to variable
		
		if (input == 'i') //if input = i
		{
			insert(p1, n); //calls func
			n++; //n increases by one
			printf("\n"); //prints that insert func was effectively done
			printf("You successfully entered that player into the database.\n");
		}
		else if (input == 'r') //if input = r
		{
			int res = Remove(p1, n); //calls remove and sets equal to res
			if (res == 2) //only when remove returns 2 is when n decreases
				n--; 
		}
		else if (input == 's') //if input = s 
			Search(p1, n); //calls func
		else if (input == 'd') //if input = d
			display(p1, n); //calls func
		else if (input == 'm') //if input = m
			options(); //calls func
		else if (input == 'e') //if input = e
		{
			printf("\n"); //ends loop
			printf("Thank you for using the National Basketball Association (NBA) General Records\n");
		}
		else //else prints error statement
		{
			printf("Sorry that is not one of the options.\n");
			printf("You can enter 'M' to see the options again.\n");
		}
	}
	
	FILE *inp;
	inp = fopen("datafile.txt","w");
	for (int x = 0; x < n; x++)
	{
		fprintf(inp,"------------------------------------------\n");
		fprintf(inp, "Player #%d\n", x+1);
		fprintf(inp, "Rank: %d\n", p1[x].Rank);
		fprintf(inp, "First Name: %s\n", p1[x].FirstName);
		fprintf(inp, "Last Name: %s\n", p1[x].LastName);
		fprintf(inp, "Height (in inches): %d\n", p1[x].Height);
		fprintf(inp, "Points per Game: %.1f\n", p1[x].PPG);
	}
	
	fclose(inp);
}

void intro()
{
	printf("National Basketball Association (NBA) General Records\n"); //print statements
	printf("-----------------------------------------------------------\n");
	printf("With these records you can insert, remove, search, and display\n");
	printf("a specific player's general records\n");
	printf("-----------------------------------------------------------\n");
	printf("We have provided a few records of legendary players for you.\n");
	printf("Now you are in full control!\n");
}
void options()
{
	printf("-----------------------------------------------------------\n");
	printf("Your options are: \n"); //option print statements
	printf("I = Insert a new record into database.\n");
	printf("R = Remove a pre-existing record from database.\n");
	printf("S = Search for a specific record in database.\n");
	printf("D = Display all items in the database.\n");
	printf("M = Display this menu of options again.\n");
	printf("E = Exit this program.\n");
}

void hardcode(player p1[SIZE])
{
	
	//hardcodes values into struct
	//Player #1
	p1[0].Rank = 1;
	strcpy(p1[0].FirstName, "Michael");
	strcpy(p1[0].LastName, "Jordan");
	p1[0].Height = 78;
	p1[0].PPG = 30.1;
	
	//Player #2
	p1[1].Rank = 2;
	strcpy(p1[1].FirstName, "Lebron");
	strcpy(p1[1].LastName, "James");
	p1[1].Height = 81;
	p1[1].PPG = 27.3;
	
	//Player #3
	p1[2].Rank = 3;
	strcpy(p1[2].FirstName, "Kareem");
	strcpy(p1[2].LastName, "Abdul-Jabbar");
	p1[2].Height = 86;
	p1[2].PPG = 24.6;
	
	//Player #4
	p1[3].Rank = 4;
	strcpy(p1[3].FirstName, "Magic");
	strcpy(p1[3].LastName, "Johnson");
	p1[3].Height = 81;
	p1[3].PPG = 19.5;
	
	//Player #5
	p1[4].Rank = 5;
	strcpy(p1[4].FirstName, "Larry");
	strcpy(p1[4].LastName, "Bird");
	p1[4].Height = 81;
	p1[4].PPG = 24.3;
	
	//Player #6
	p1[5].Rank = 6;
	strcpy(p1[5].FirstName, "Kobe");
	strcpy(p1[5].LastName, "Bryant");
	p1[5].Height = 78;
	p1[5].PPG = 25.0;
	
	//Player #7
	p1[6].Rank = 7;
	strcpy(p1[6].FirstName, "Shaquille");
	strcpy(p1[6].LastName, "O'Neal");
	p1[6].Height = 85;
	p1[6].PPG = 23.7;
	
	
}

void display(player p1[SIZE], int n)
{
	for (int x = 0; x < n; x++) //displays all struct values
	{
		printf("------------------------------------------\n");
		printf("Player #%d\n", x+1);
		printf("Rank: %d\n", p1[x].Rank);
		printf("First Name: %s\n", p1[x].FirstName);
		printf("Last Name: %s\n", p1[x].LastName);
		printf("Height (in inches): %d\n", p1[x].Height);
		printf("Points per Game: %.1f\n", p1[x].PPG);
	}
}

void insert(player p1[SIZE], int n)
{
	printf("-----------------------------------------------------------\n");
	printf("You chose the insert option.\n"); //print statements
	printf("This allows you to insert your own record into this database.\n");
	printf("Please enter your data below: \n");
	printf("Enter the players rank: "); //accepts inputs for records
	scanf("%d", &p1[n].Rank);
	printf("Enter the players FIRST name: ");
	scanf("%s", p1[n].FirstName);
	printf("Enter the players LAST name: ");
	scanf("%s", p1[n].LastName);
	printf("Enter the players height in INCHES: ");
	scanf("%d", &p1[n].Height);
	printf("Enter the players points per game: ");
	scanf("%lf", &p1[n].PPG);
}

int Remove(player p1[SIZE], int n)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	int choice = n; //declarations
	printf("-----------------------------------------------------------\n");
	printf("You chose the remove option.\n"); //print statements
	printf("This allows you to remove a record from this database.\n");
	printf("Please enter the Player # you wish to remove below.\n");
	printf("Here is a list of the current players in the records.\n");
	printf("---\n");
	for(int x = 0; x < n; x++) //presents all players to user
	{
		printf("Player %d is %s %s.\n", x+1, p1[x].FirstName, p1[x].LastName);
	}
	printf("---\n");
	while (choice == n) //while choice = n
	{
		printf("Enter the player number here: ");
		scanf("%d", &choice); //request input
		if(choice < n)
		{
			for(int x = choice - 1; x < n; x++) //if valid input then right hand shift of struct value
			{
				player temp = p1[x + 1];
				p1[x] = p1[x-1];
				p1[x] = temp;
			}
			return 2;
		}
		else if(choice == n) //removes value
		{
			break;
			return 2;
		}
		else //prints error statement and returns 1
		{
			printf("Sorry there is no player with that number.\n");
			printf("Please enter again.\n");
			return 1;
		}
	}
}

void Search(player p1[SIZE], int n)
{
	printf("You chose the search option.\n"); //print statements
	printf("You can filter through the records in many different ways.\n");
	printf("----\n");
	printf("If you want to sort through by Player #, enter 'p'.\n");
	printf("If you want to sort through by Rank, enter 'r'.\n");
	printf("If you want to sort through by First Name, enter 'f'.\n");
	printf("If you want to sort through by Last Name, enter 'l'.\n");
	printf("----\n");
	
	char p, r, f, l; //bunch of declarations
	int plnum, nrank, num;
	char user, preuser;
	char firname[SIZE], lasname[SIZE];
	
	printf("Enter your choice of filter: ");
	scanf(" %c", &preuser);
	user = tolower(preuser); //accepts input then lowers it
	while (user == 'p' || 'r' || 'f' || 'l') 
	{
		if (user == 'p') //if input = p
		{
			printf("---\n"); //request player number
			printf("Now, Enter the player number whose record you want to see: ");
			scanf(" %d", &plnum);
			if (p <= n)
			{
				printf("---\n"); //prints requested player
				printf("Player #%d\n", plnum);
				printf("Rank: %d\n", p1[plnum-1].Rank);
				printf("First Name: %s\n", p1[plnum-1].FirstName);
				printf("Last Name: %s\n", p1[plnum-1].LastName);
				printf("Height (in inches): %d\n", p1[plnum-1].Height);
				printf("Points per Game: %.1f\n", p1[plnum-1].PPG);
				break;
			}
			else //prints error 
			{
				printf("Sorry there is no player in the database with that number.\n");
				break;
			}
		}
		else if(user == 'r') //if input = r
		{
			printf("---\n"); //request player rank
			printf("Now, Enter the player's rank whose record you want to see: ");
			scanf(" %d", &nrank);
			if (r <= n)
			{
				printf("---\n"); //prints requested player
				printf("Player #%d\n", nrank);
				printf("Rank: %d\n", p1[nrank-1].Rank);
				printf("First Name: %s\n", p1[nrank-1].FirstName);
				printf("Last Name: %s\n", p1[nrank-1].LastName);
				printf("Height (in inches): %d\n", p1[nrank-1].Height);
				printf("Points per Game: %.1f\n", p1[nrank-1].PPG);
				break;
			}
			else //prints error
			{
				printf("Sorry there is no player in the database with that ranking number.\n");
				break;
			}
		}
		else if(user == 'f') //if input = f
		{
			printf("---\n"); //request input
			printf("If nothing is presented it means there is no player with that name in the database.\n");
			printf("Now, Enter the player's first name (Capitalize the first letter of name)whose record you want to see: ");
			scanf(" %s", firname);
			for (int x = 0; x < n; x++)
			{
				if (strcmp(firname, p1[x].FirstName) == 0)
				{
					num = x;
					printf("---\n"); //prints requested player
					printf("Player #%d\n", num+1);
					printf("Rank: %d\n", p1[num].Rank);
					printf("First Name: %s\n", p1[num].FirstName);
					printf("Last Name: %s\n", p1[num].LastName);
					printf("Height (in inches): %d\n", p1[num].Height);
					printf("Points per Game: %.1f\n", p1[num].PPG);
					break;
				}
			}
			
			break;
		}
		else if(user == 'l') //if input = l
		{
			printf("---\n"); //request input of last name
			printf("Now, Enter the player's last name (Capitalize the first letter of name) whose record you want to see: ");
			scanf(" %s", lasname);
			for (int x = 0; x < n; x++)
			{
				if (strcmp(lasname, p1[x].LastName) == 0)
				{
					num = x;
					printf("---\n"); //prints requested player
					printf("Player #%d\n", num+1);
					printf("Rank: %d\n", p1[num].Rank);
					printf("First Name: %s\n", p1[num].FirstName);
					printf("Last Name: %s\n", p1[num].LastName);
					printf("Height (in inches): %d\n", p1[num].Height);						printf("Points per Game: %.1f\n", p1[num].PPG);
					break;
				}
			}
			break;
		}
		else //else prints error
		{
			printf("Please select from one of the four options.\n");
			break;
		}
			
	}
}
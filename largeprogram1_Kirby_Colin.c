//Colin Kirby
//Dr. Steinberg
//COP3223C
//Large Program 1 Skeleton

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

int main()
{
	greeting(); //display greeting message
	
	
	//setup random generator
	int seed;
	printf("Before we start, pick a number to determine how random I will be.\n");
	scanf("%d", &seed);
    srand(seed);
	printf("All set now!\n");
	
	for(int x = 0; x < ROUNDS; ++x)
	{
		playRound(x + 1);
	}
	
	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;
}


void playRound(int round)
{
	printf("Welcome to a new round %d!\n", round);
	printf("Best out of three...Let's go!\n");
	
	int p1wins = 0;
	int p2wins = 0;
	int draw; // New declaration statements
	
	//loop that keeps track of wins until respective player reaches 3. we will learn about conditional loops soon :)
	while(p1wins != 3 && p2wins != 3)
	{
		printf("********************************************************\n");
		printf("Player 1 has won %d times.\n", p1wins); //Print statements
		printf("Player 2 has won %d times.\n", p2wins);
		int player1 = pickOne(); //Sets player1 = to the returned value from function pickOne
		int player2 = computerPick(); //Sets player2 = to the returned value from function computerPick
		int win; // Declares new int
		win = battle(player1, player2); //Sets win equal to the value returned from function battle
		if (win == 10) // Acts as the sort of counter for the number of wins within a round through a series of if-else if statments
		{
			if (player1 == 1)
			{
				printf("Rock beats Scissor!\n");
				printf("********************************************************\n");
				p1wins = p1wins + 1;
			}
			else if (player1 == 2)
			{
				printf("Paper beats Rock!\n");
				printf("********************************************************\n");
				p1wins = p1wins + 1;
			}
			else if (player1 == 3)
			{
				printf("Scissor beats Paper!\n");
				printf("********************************************************\n");
				p1wins = p1wins + 1;
			}
		}
		else if (win == 20)
		{
			if (player1 == 1)
			{
				printf("Paper beats Rock!\n");
				printf("********************************************************\n");
				p2wins = p2wins + 1;
			}
			else if (player1 == 2)
			{
				printf("Scissor beats Paper!\n");
				printf("********************************************************\n");
				p2wins = p2wins + 1;
			}
			else if (player1 == 3)
			{
				printf("Rock beats Scissor!\n");
				printf("********************************************************\n");
				p2wins = p2wins + 1;
			}
		}
		else if (win == 30)
		{
			printf("Draw!\n");
			printf("********************************************************\n");
		}
	}
	int player1 = p1wins; // Redeclares player1 to p1wins for result function parameters
	int player2 = p2wins; // Redeclares player2 to p2wins for result function parameters
	result(player1,player2); //Calls back function result following the while loop completion
}


void greeting() //Prints greeting message
{
	printf("********************************************************\n");
	printf("Welcome to rock paper scissor game!\n");
	printf("Here are the rules.\n");
	printf("You and I will get to choose rock, paper, or scissor.\n");
	printf("After we made a decision we will reveal it and determine the winner based on these rules!\n");
	printf("Rock beats Scissor!\n");
	printf("Paper beats Rock!\n");
	printf("Scissor beats Paper!\n");
	printf("If we both pick the same option, then it is a tie.\n");
	printf("Ready to play?...Here we go!\n");
	printf("********************************************************\n");
}

int pickOne() // Retrieves user's guess
{
	int player1; //Declaration statement
	printf("1---Rock\n");
	printf("2---Paper\n");
	printf("3---Scissor\n");
	printf("Make your selection: ");
	scanf("%d", &player1); // Accepts input from user and returns input as player1
	return player1;
}

int computerPick() // Creates computers guess
{
	int player2; 
	player2 = (rand() % 3); // Sets player2 = to a random value between 0,2
	player2 = player2 + 1;  // Adds 1 so it is the range 1 to 3
	printf("I'm making my decision now.\n");
	return player2; // Returns rand value between 1 and 3
}

int battle(int player1, int player2) // Produces each individual game 
{
	int a = 10; //Sets ints to values to simplify function
	int b = 20;
	int c = 30;
	if (player1 == 1) //Series of if else if statements depending on both the users input and computer pick 
	{
		if (player2 == 1)
		{
			printf("Player1 and Player2 both used Rock!\n");
			return c;
		}
		else if (player2 == 2)
		{
			printf("Player 1 used Rock and Player 2 used Paper!\n");
			return b;
		}
		else if (player2 == 3)
		{
			printf("Player 1 used Rock and Player 2 used Scissor!\n");
			return a;
		}
	}
	else if (player1 == 2)
	{
		if (player2 == 1)
		{
			printf("Player 1 used Paper and Player 2 used Rock!\n");
			return a;
		}
		else if (player2 == 2)
		{
			printf("Player1 and Player2 both used Paper!\n");
			return c;
		}
		else if (player2 == 3)
		{
			printf("Player 1 used Paper and Player 2 used Scissor!\n");
			return b;
		}
	}
	else if (player1 == 3)
	{
		if (player2 == 1)
		{
			printf("Player 1 used Scissor and Player 2 used Rock!\n");
			return b;
		}
		else if (player2 == 2)
		{
			printf("Player 1 used Scissor and Player 2 used Paper!\n");
			return a;
		}
		else if (player2 == 3)
		{
			printf("Player1 and Player2 both used Scissor!\n");
			return c;
		}
	}
	else
	{
		printf("Someone made an invalid choice.\n"); //Prints if a value other than 1-3 is inputted or returned
		printf("********************************************************\n");
	}
}

void result(int player1, int player2)
{
	printf("********************************************************\n");
	if (player1 == 3) // Print statements based on who won each round.
		printf("You won! I'll let you have this one\n");
	else if (player2 == 3)
		printf("I won! Haha better luck next time!\n");
}

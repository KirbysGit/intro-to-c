//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Large Program 3

#include<stdio.h> //libraries
#include<string.h>
#include<ctype.h>

#define SIZE 20
#define MaxSTRK 6

void rules(); //displays rules of the game
void maskWord(char starword[], int size);
int playRound(char starword[], char answer[]);
int occurancesInWord(char userguess, char answer[]);
void updateStarWord(char starword[], char answer[], char userguess);
void playAgain(int *play);

int main()
{
	rules(); // prints rules
	
	FILE *words; //declarations
	char starword[SIZE];
	char answer[SIZE];
	
	words = fopen("words.txt","r"); //opens file
	
	int fun = 0; //declaration
	
	fscanf(words, "%s", answer); //scans first word
	
	while (fun != 2)
	{
		strcpy(starword, answer); //copies answer to starword
	
		int size = strlen(answer); //takes len of answer
		
		printf("\n");
		printf("Welcome to the Round!\n"); //print statements
		printf("The size of the word has %d letters.\n", size);
		printf("\n");
		
		maskWord(starword, size); //calls func maskWord
	
		int res = playRound(starword, answer); //calls func playRound and sets return val = to res
	
		if (res == 0) //if return val = 0 then
			printf("Sorry you did not win the round. The word was %s.\n", answer); //prints this
		else if (res == 1) //if return val = 1 then 
			printf("Congratulations! You won! The word was %s.\n", answer); //prints this
	
		int *play = &fun; //declares pointer

		playAgain(&fun); //calls func
			
		printf("\n");
	
		fscanf(words, "%s\n", answer); //scans next word from words file
	}
	
	printf("Thank you for playing today!\n"); //once user enters 2 into playAgain loop will end
	printf("\n");
	
	fclose(words); //closes words file
	return 0;
}

void rules()
{
	printf("Welcome to the Hangman Game!\n"); //print statements
	printf("Here are the rules.\n");
	printf("I will provide you a set of * characters for each round.\n");
	printf("Each * represents a letter in the English Alphabet.\n");
	printf("You must figure out the letter of the missing word.\n");
	printf("For every correct letter guessed, I will reveal its place in the word.\n");
	printf("Each mistake will result in a strike.\n");
	printf("6 strikes will result in a loss that round.\n");
	printf("Are you ready? Here we go!\n");
}

void maskWord(char starword[], int size)
{
	for (int x = 0; x < size; x++) //for x < len of word sets each char = to *
	{
		if (isalpha(starword[x]) > 0)
			starword[x] = '*';
	}
}

int playRound(char starword[], char answer[])
{
	char guessltrs[SIZE] = ""; //declarations
	int strk = 0;
	char gs;
	int siza = strlen(answer);
	
	while (MaxSTRK > strk && strcmp(starword, answer) != 0) //while strk < 6 or 
	{
		printf("You currently have %d strike(s).\n", strk); //displays # of strikes
		printf("Letter(s) you have guessed: %s\n", guessltrs); //displays ltrs guessed
		printf("\n");
		printf("%s\n", starword); //prints stars
		printf("\n");
	
		
		printf("Enter your guess: "); //request input char
		scanf(" %c", &gs);
		
		if (isalpha(gs) == 0) //if gs is not ltr
		{
			while (isalpha(gs) == 0)
			{
				printf("\n");
				printf("You did not enter a letter from the alphabet.\n"); //prints error msg
				printf("\n");
				
				break;
			}
		}
		else if (isalpha(gs) > 0) //if gs is ltr
			printf("\n"); //print newline
		
		char userguess = tolower(gs); //lowers case of char
		strncat(guessltrs, &userguess, 1); //adds the char to guessltrs list
		
		int wvl = occurancesInWord(userguess, answer); //calls func and sets = to wvl
	
		if (wvl == 0) //if wvl = 0 
		{
			printf("The letter %c is NOT the word.\n", userguess); //prints this
			printf("\n");
			strk++; //number of strikes increases by one
		}
		else if(wvl > 0) //if wvl is greater than 0 
		{
			printf("The letter %c is in the word.\n", userguess); //prints this
			printf("\n");
			updateStarWord(starword, answer, userguess); //calls func
		}
	}
	
	if (strk == MaxSTRK) //once loop ends if strk = 6 
		return 0; //returns 0 
	else if(strcmp(answer, starword) == 0) //else if two strings are same 
		return 1; //returns 1
}

int occurancesInWord(char userguess, char answer[])
{
	int size = strlen(answer); //declarations
	int count = 0;
	char *ptr = strchr(answer, userguess);
	if (ptr == NULL) //if value is NULL then it is not in word
		return 0;
	else //if ptr holds address then 
	{
		for (int x = 0; x < size; x++) //for x < len of answer
			if (answer[x] == userguess) //if guessed char = a ltr in answer
				count = count + 1;//the count increases
		return count; //returns count
	}		
}

void updateStarWord(char starword[], char answer[], char userguess)
{
	int alen = strlen(answer); //takes entered value and 
	for (int x = 0; x < alen; x++) //for x < len of word
	{
		if (answer[x] == userguess) //if answer = the input of user
		{
			starword[x] = userguess; //the star is removed and letter replaces its index
		}
	}
}

void playAgain(int *play)
{
	printf("Would you like to play another round?\n"); //print statements
	printf("1: Yes\n");
	printf("2: No\n");
	printf("Choice: ");
	scanf("%d", play); //accepts input
}
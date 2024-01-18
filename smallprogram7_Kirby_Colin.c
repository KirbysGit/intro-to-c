//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 7

#include<stdio.h> //libraries
#include<string.h>
#include<ctype.h>

#define SIZE 20 //definitions
#define SIZE2 20
#define SIZE3 20
#define SIZE4 20

char *deblank(char input[SIZE], char output[SIZE]); //prototypes
char *pluralize(char noun[SIZE2], char plnoun[SIZE2]);
char *fact(char numbers[SIZE3]);
char *substring(char str1[SIZE4], char str2[SIZE4]);

int main()
{
	//Problem #1
	char input[SIZE]; //declarations
	char output[SIZE];
	printf("Enter a string: "); //request input from user
	fgets(input, SIZE, stdin);
	printf("Input String: %s", input); //prints out original input
	strcpy(output, input); //copies input str to output str
	printf("\n");
	deblank(input, output); //calls func
	printf("Output String: %s\n", output); //prints output string after func
	
	//Problem #2
	char noun[SIZE2]; 
	char plnoun[SIZE2] = ""; //declarations
	printf("Enter string to be pluralize: "); //accepts input
	scanf("%s", noun);
	pluralize(noun, plnoun);// calls func
	printf("Word pluralize: %s\n", plnoun); //prints new word
	
	//Problem #3
	char numbers[SIZE3]; //declaration
	printf("Enter a string with no spaces: "); //accepting input
	scanf("%s", numbers); //accepts input to numbers
	fact(numbers); //calls func
	
	//Problem #4
	char str1[SIZE4]; //declarations
	char str2[SIZE4];
	printf("Enter a string 1: "); //request two string input from user
	scanf("%s", str1);
	printf("Enter a string 2: ");
	scanf("%s", str2);
	char *ptr = substring(str1, str2); //uses ptr to call func
	printf("function return %p\n", ptr); //prints either address or null
}

char *deblank(char input[SIZE], char output[SIZE])
{
	
	return output; //returns output string
}

char *pluralize(char noun[SIZE2], char plnoun[SIZE2])
{
	char end1[SIZE2] = "ies"; //declarations
	char end2[SIZE2] = "es";
	char end3[SIZE2] = "s";
	int z = strlen(noun);
	
	for (int x = z - 1; x >= 0; x--) //uses for loop to generate starting from last char 
	{
		if (noun[x] == 'y') //if y adds end 1
		{
			strncpy(plnoun, noun, z - 1);
			strcat(plnoun, end1);
			break;
		}
		else if (noun[x] == 's') //if s adds end 2 
		{
			strncpy(plnoun, noun, z);
			strcat(plnoun, end2);
			break;
		}
		else if (noun[x] == 'h') //if h then
		{
			if(noun[x-1] == 'c' || 's') //if s or c before h add end2
			{
				strncpy(plnoun, noun, z);
				strcat(plnoun, end2);
				break;
			}
			else //if else add end 3
			{
				strcat(noun, end3); 
				break;
			}
		}
		else //else just add end3
		{
			strncpy(plnoun, noun, z);
			strcat(plnoun, end3);
			break;
		}
	}
	return plnoun; //return new pluralized string
}

char *fact(char numbers[SIZE3])
{
	// ab12c,3?ad.!!xO
	int punc = 0; //declarations
	int digit = 0;
	int ltr = 0;	
	
	int y = strlen(numbers); //takes length of string
	numbers[y] = '\0';
	printf("%s has\n", numbers); //prints input string
	for (int x = 0; x < y;  x++) //for index in array
	{
		if (isalpha(numbers[x]) > 0) //if char is letter
			ltr = ltr + 1; // ltr + 1
		else if(ispunct(numbers[x]) > 0) //if char is punct
			punc = punc + 1; // punc + 1
		else if(isdigit(numbers[x]) > 0) // if char is num
			digit = digit + 1; // digit + 1
	}
	printf("%d letters\n", ltr); //prints all vars
	printf("%d digits\n", digit);
	printf("%d punctuation characters\n", punc);
}

char *substring(char str1[SIZE4], char str2[SIZE4])
{
	int a = strlen(str1)- 1; //takes len of string -1 for indexes
	int b = strlen(str2)- 1;
	for (int x = b; x <= a; x++) //for x = len of str 2 and x < len of str1 x++
	{
		for (int y = 0; y <= b; y++)
		{
			if (str1[x] == str2[y]) //if chars equal eachother then it returns adress of first char of string
			{
				return &str2[0];
			}
			else //else returns null
			{
				return 0;
			}
		}
	}
}



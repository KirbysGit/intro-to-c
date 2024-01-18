#include<stdio.h>
#include<string.h>
void counter(char arr[]);

int main()
{

    // QUESTION #1

    int grades[5]; //declarations
    int i;

    for (i = 0; i < 5; i++) // for loop to prompt for grade entries
    {
        printf("Please enter a grade here: ");
        scanf("%d", &grades[i]);
        getchar(); //gets rid of newline character to allow for fgets
    }

    int min, max; //declarations

    min = grades[0];
    for (i = 0; i < 4; i++) //minimum finder
    {
        if (grades[i+1] < min)
            min = grades[i + 1];
    }

    max = grades[0];
    for (i = 0; i < 4; i++) //maximum finder
    {
        if (grades[i+1] > max)
            max = grades[i + 1];
    }

    if (min < 60) // if else statement for corresponding letter grade for max and min
        printf("Minimum grade is %d (F).\n", min);
    else if (min >= 60 &&  min < 70)
        printf("Minimum grade is %d (D).\n", min);
    else if (min >= 70 && min < 80)
        printf("Minimum grade is %d (C).\n", min);
    else if (min >= 80 && min < 90)
        printf("Minimum grade is %d (B).\n", min);
    else if (min >= 90)
        printf("Minimum grade is %d (A).\n", min);

    if (max < 60)
        printf("Maximum grade is %d (F).\n", max);
    else if (max >= 60 &&  max < 70)
        printf("Maximum grade is %d (D).\n", max);
    else if (max >= 70 && max < 80)
        printf("Maximum grade is %d (C).\n", max);
    else if (max >= 80 && max < 90)
        printf("Maximum grade is %d (B).\n", max);
    else if (max >= 90)
        printf("Maximum grade is %d (A).\n", max);

    printf("\n");

// QUESTION #2

    char set[50]; //declaration

    printf("Enter a sentence: "); //requestion
    fgets(set, sizeof(set), stdin);

    counter(set);
    printf("\n");
    printf("\n");

// QUESTION #3

    int arr[2][4] = {{1,2,3,4},{5,6,7,8}}; //initialize array

    int j;
    for (i = 0; i < 2; i++) // original print nested for loops
    {
        for (j = 0; j <= 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++) // modifier loop
    {
        for (j = 0; j <= 3; j++)
        {
            arr[i][j] = arr[i][j] * 5; // multiply each value by 5
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++) // second print loop
    {
        for (j = 0; j <= 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}


void counter(char arr[])
{
    int sumE = 0; //declarations
    int sumA = 0;
    int i;

    for (i = 0; arr[i] != '\0'; i++) //for loop to iterate through char []
    {
        if (arr[i] == 'a' || arr[i] == 'A') // if A or E the int increases
            sumA++;
        else if(arr[i] == 'e' || arr[i] == 'E')
            sumE++;
    }

    printf("Number of As are: %d", sumA); //print statements
    printf("\n");
    printf("Number of Es are: %d", sumE);
}



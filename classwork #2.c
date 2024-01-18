#include<stdio.h>

int main()
{
  int grade;

  printf("Hello! , Please enter a grade here: ");
  scanf("%d", &grade);

  if (grade <= 59 && grade >= 0)
    printf("Grade: F \n");
  else if (grade <= 69 && grade >= 60)
    printf("Grade: D \n");
  else if (grade <= 79 && grade >= 70)
    printf("Grade: C \n");
  else if (grade <= 89 && grade >= 80)
    printf("Grade: B \n");
  else if (grade <= 100 && grade >= 90)
    printf("Grade: A \n");
  else
    printf("Please enter an integer between 0 and 100.");

  printf("\n");
  int i;
  for (i = 0; i < 10; i++)
  {
    printf("Please enter another grade here:  ");
    scanf("%d", &grade);

    if (grade <= 59 && grade >= 0)
        printf("Grade: F \n");
    else if (grade <= 69 && grade >= 60)
        printf("Grade: D \n");
    else if (grade <= 79 && grade >= 70)
        printf("Grade: C \n");
    else if (grade <= 89 && grade >= 80)
        printf("Grade: B \n");
    else if (grade <= 100 && grade >= 90)
        printf("Grade: A \n");
    else
        printf("Please enter an integer between 0 and 100. \n");
  }




    return 0;
}

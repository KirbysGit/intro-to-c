

#include<stdio.h>

int avgarr(int arr2[]);

int main()
{
    // part #1
    int i;
    int num[] = {10, 20, 30, 40, 50};
    for (i = 0; i < 5; i++)
        printf("%d ", num[i]);


    printf("\n");
    int x = num[4];
    num[4] = num[0];
    num[0] = x;
    for (i = 0; i < 5; i++)
        printf("%d ", num[i]);

    // part #2
    printf("\n");
    printf("\n");
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    printf("Average: %d\n", avgarr(arr));




}

int avgarr(int arr2[])
{
    int z;
    int avg;
    int sum = 0;

    for (z = 0; z < 10; z++)
    {
        sum = sum + arr2[z];
    }

    int num = z;
    avg = sum / num;

    return avg;
}

//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 6

#include<stdio.h>
#include<stlib.h>

#define SIZE 1000

void display(int arr[]);

int main
{
	int arr[size];
	int seed;
	printf("Enter a seed: ");
	scanf("%d", &seed);
	srand(seed); 
	
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1;
	}
	
	
	return 0;
}

void display(int arr[])
{
	for(int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");
}

void  meanMinMax(int arr[])
{
	double min, max, mean, total;
	int i, j, k;
	
	min = arr[0];
	for (i = 1; i < SIZE; i++){
		if (arr[i] < min){
			min = arr[i];
		}
	}
	
	max = arr[0];
	for(j = 1; j < SIZE; j++){
		if (arr[j] > max){
			max = arr[j];
		}
	}
	
	for (k = 1; k < SIZE; k++){
		total = total + arr[k];
		mean = sum / (k + 1);
	}
	
	printf("Average: %lf\n", mean);
	printf("Max: %lf\n", max);
	printf("Min: %lf\n", min);
		
	
}
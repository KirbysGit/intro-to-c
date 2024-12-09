//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Small Program 6

#include<stdio.h> //libraries
#include<stdlib.h>

#define SIZE 1000 //def for size

void display(int arr[]); //prototypes
void  meanMinMax(int arr[]);
void mySort(int arr[]);
void doubleShift(int arr[]);
void reverse(int arr[]);

int main()
{
	int arr[SIZE]; //code we were given
	int seed;
	printf("Enter a seed: ");
	scanf("%d", &seed);
	srand(seed); 
	
	for (int x = 0; x < SIZE; x++) //assigns values to each index of array
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1;
	}
	
	meanMinMax(arr); //calls meanMinMax function
	printf("\n");
	
	mySort(arr); //calls mySort function
	display(arr); // displays changed array
	
	doubleShift(arr); //calls doubleShift function
	display(arr);// displays changed array
	
	reverse(arr); //calls reverse function
	display(arr); // displays changed array
	
	return 0;
}

void display(int arr[])
{
	for(int x = 0; x < SIZE; x++) //displays each value based on index
		printf("%6d ", arr[x]);
	
	printf("\n");
}

void meanMinMax(int arr[])
{
	double min, max, mean, total; //declarations
	int i, j, k;
	
	min = arr[0]; //sets equal to first index value
	for (i = 1; i < SIZE; i++){ //for i less than 1000 i increases
		if (arr[i] < min){ //until it finds the lowest value
			min = arr[i]; //which it then saves to the i'th index
		}
	}
	
	max = arr[0]; //sets equal to first index value
	for(j = 1; j < SIZE; j++){ //for j less than 1000 j increases
		if (arr[j] > max){ //until it finds the greatest value
			max = arr[j]; //which it then saves to the j'th value
		}
	}
	
	for (k = 0; k < SIZE; k++){ // for k less than size
		total = total + arr[k]; // adds up the values of each index value
		mean = total / (k + 1); //then divided by number of indexes + 1
	}
	
	printf("Average: %lf\n", mean); //print statements
	printf("Max: %.0lf\n", max);
	printf("Min: %.0f\n", min);
		
	
}

void mySort(int arr[])
{
	int l, m, n; //declaration statements
	for (l = 0; l < SIZE; l++){ //nested for loops to increase int's individually until it is 999
		for(m = l+1; m < SIZE; m++){
			if (arr[l] > arr[m]){ //if value of l index is greater than value of m index then
				n = arr[l]; //sets greater value = to arr[l], n acts as a temp variable
				arr[l] = arr[m]; //then sets value = to arr[m]
				arr[m] = n; //then arr[m] equal to n
			}
		}
	}
	
}

void doubleShift(int arr[])
{
	int n; //declaration
	for (n = SIZE; n >= 0; n--){ //while n is greater than or equal to 0 n decreases
		if (n >= 1) // serves as main change of index because most values fall into this condition
			arr[n] = arr[n-2];
		else if (n < 1) // serves to change index of the final two values 
			arr[n] = arr[n + 1000];
		}
}

void reverse(int arr[])
{
	int a, b, c; //declaration
	for(a = SIZE - 1; a > 0; a--){ //nested for loops similar to mySort function in reverse
		for(b = a - 1; b >= 0; b--){ //subtracts from SIZE per each int a and b and compares the values
			if (arr[a] > arr[b]){ //then if val a is greater than val b
				c = arr[a]; // changes values of each specific index to diff val
				arr[a] = arr[b];
				arr[b] = c; // c acts as temp val
			}
			else if (arr[a] < arr[b]){ //because of the doubleShift function the val of first indexes were greater
				c = arr[a]; // so to make sure they are in right indexes this else if
				arr[a] = arr[b]; // does that
				arr[b] = c;
			}
		}
	}
}
//Colin Kirby
//Dr. Steinberg
//COP3223C Section 1
//Large Program 4

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMIT 50

typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
}record_t;

record_t * createArray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize); 
void display(record_t *myarray, int currentsize);
record_t *doubleIt(record_t *arr, int size); 
int removeRecord(record_t *arr, int size, int index); 
void freeRecords(record_t *arr, int size); 

int main(void)
{
	int maxsize;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);


	record_t *myarray = createArray(maxsize); //declares ptr to struct
	
	int currentsize = 0; //declarations
	int option = -1;

	while(option != 0) //while loop
    {
        printf("What would you like to do?\n"); //print statements
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option); //Gets rid of newline char

        switch(option)
        {
            case 1: //if 1
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize); //calls func
                break;

            case 2: //if 2
                printf("Display was selected...\n");
                display(myarray, currentsize); //calls func
                break;

            case 3: //if 3
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n"); //request input
                int index;
                scanf("%d", &index);
                currentsize = removeRecord(myarray,currentsize,index); //calls func
                break;

            case 4:
                printf("Exiting...\n");
                option = 0; //sets option = 0
				break;

            default:
                printf("Invalid Selection...\n"); // else prints this

        }

    }
	
	freeRecords(myarray, currentsize); //calls func
	free(myarray); //frees ptr 

	myarray = NULL; //declares arr as null

	return 0;
}

record_t * createArray(int maxsize)
{
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t));
	
	if(arr == NULL)
	{
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	
	return arr;
}
void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x) //for loop
	{
	    printf("myarray[%d].fname = %s\n", x, (x + myarray)->fname); //try it with myarray[x].name
		printf("myarray[%d].lname = %s\n", x, (x + myarray)->lname); //try it with myarray[x].name
		printf("myarray[%d].show = %s\n", x, (x + myarray)->show); //try it with myarray[x].show
	}

	printf("---------------------------------\n");
}
record_t * insert(record_t *myarray, int *maxsize, int *currentsize)
{
	if (*currentsize == *maxsize)
	{
		printf("Array is full...Need to doubleIt...\n"); 
		myarray = doubleIt(myarray, *currentsize); //sets myarray = to doubled size
		*maxsize = *maxsize * 2;
	}
	else if(*currentsize < *maxsize)
	{
		(myarray + *currentsize)->fname = (char *) malloc(sizeof(record_t)); //malloc statements
		(myarray + *currentsize)->lname = (char *) malloc(sizeof(record_t));
		(myarray + *currentsize)->show = (char *) malloc(sizeof(record_t));
		
		printf("Enter the first name: ");
		scanf("%s", myarray[*currentsize].fname);
		
		
		printf("Enter the last name: ");
		scanf("%s", myarray[*currentsize].lname);
		getchar();
		
		
		printf("Enter favorite show: ");
		fgets(myarray[*currentsize].show, LIMIT, stdin);

		(*currentsize)++; //increases int by 1
	}
	
	return myarray;
}

record_t *doubleIt(record_t *arr, int size)
{
	record_t * temp = (record_t *) malloc(sizeof(record_t) * size * 2); //malloc of temp
	if(temp == NULL) //if temp doesnt malloc properly
	{
		printf("Malloc error in double it... program exiting\n");
		exit(1);
	}
	
	for (int i = 0; i < size; i++) //for loop to sets previous arr = to new one
	{
		strcpy(temp[i].fname, arr[i].fname);
		strcpy(temp[i].lname, arr[i].lname);
		strcpy(temp[i].show, arr[i].show);
	}
	
	for (int x = 0; x < size; x++)
	{
		free((arr + x)->fname);
		free((arr + x)->lname);
		free((arr + x)->show);
	}
	
	free(arr);
	arr = NULL;
	
	return temp; //returns new arr
}

int removeRecord(record_t *arr, int size, int index)
{
	record_t temp; //acts as temp to switch for remove func
	if (index <= size)
	{
		for (int x = index; x < size; x++)
		{
			strcpy(temp,arr[x+1]); //right hand shift
			strcpy(arr[x], arr[x-1]);
			strcpy(arr[x], temp);
		}
		return size - 1;
	}
	else
	{
		printf("Invalid Index\n");
		return size;
	}
}

void freeRecords(record_t *arr, int size)
{
	for (int x = 0; x < size; x++)
	{
		free((arr + x)->fname);
		free((arr + x)->lname);
		free((arr + x)->show);
	}
}

//confused on how to properly figure out memory leaks
// keep getting 3 errors and 144 bytes in 6 blocks
#include<stdio.h>

struct employee {
	char fname[15];
	char lname[15];
	int age;
	double salary;
	double zip;
};


int main ()
{

    // PART #1

    // Initialize Struct with random values
	struct employee Emp1 = {"Colin", "Kirby", 19, 20000, 32386};
	struct employee Emp2 = {"Joe", "Brown", 24, 24000, 67896};
	struct employee Emp3 = {"Peyton", "Smith", 21, 30000, 98764};

	// Dot operator

	//first employee
	printf("\nFirst name: %s", Emp1.fname);
	printf("\nLast Name: %s", Emp1.lname);
	printf("\nAge: %d", Emp1.age);
	printf("\nSalary: %.lf", Emp1.salary);
	printf("\nZipcode: %.lf", Emp1.zip);
    printf("\n");

	//second employee
	printf("\nFirst name: %s", Emp2.fname);
	printf("\nLast Name: %s", Emp2.lname);
	printf("\nAge: %d", Emp2.age);
	printf("\nSalary: %.lf", Emp2.salary);
	printf("\nZipcode: %.lf", Emp2.zip);
    printf("\n");

	//third employee
	printf("\nFirst name: %s", Emp3.fname);
	printf("\nLast Name: %s", Emp3.lname);
	printf("\nAge: %d", Emp3.age);
	printf("\nSalary: %.lf", Emp3.salary);
	printf("\nZipcode: %.lf", Emp3.zip);
    printf("\n");

    //Arrow operator

    struct employee *ptr1;
    ptr1 = &Emp1;

    struct employee *ptr2;
    ptr2 = &Emp2;

    struct employee *ptr3;
    ptr3 = &Emp3;

    //first employee
    printf("\nFirst name: %s", ptr1->fname);
	printf("\nLast Name: %s", ptr1->lname);
	printf("\nAge: %d", ptr1->age);
	printf("\nSalary: %.lf", ptr1->salary);
	printf("\nZipcode: %.lf", ptr1->zip);
    printf("\n");

    printf("\nFirst name: %s", ptr2->fname);
	printf("\nLast Name: %s", ptr2->lname);
	printf("\nAge: %d", ptr2->age);
	printf("\nSalary: %.lf", ptr2->salary);
	printf("\nZipcode: %.lf", ptr2->zip);
    printf("\n");

    printf("\nFirst name: %s", ptr3->fname);
	printf("\nLast Name: %s", ptr3->lname);
	printf("\nAge: %d", ptr3->age);
	printf("\nSalary: %.lf", ptr3->salary);
	printf("\nZipcode: %.lf", ptr3->zip);
    printf("\n");

    // PART #2

    int A = 10;
    int B = 20;

    printf("\n");
    printf("AND operator: %d\n", A & B);
    printf("OR operator: %d\n", A | B);
    printf("XOR operator: %d\n", A ^ B);
    printf("Complement of A: %d\n", ~A);
    printf("Complement of B: %d\n", ~B);
    printf("Right shift A by 2: %d\n", A >> 2);
    printf("Right shift B by 2: %d\n", B >> 2);
    printf("Left shift A by 2: %d\n", A << 2);
    printf("Right shift B by 2: %d\n", B << 2);

}

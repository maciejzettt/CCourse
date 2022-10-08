#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char name[40];
	int hireDate;
	float salary;
} employee;

int main()
{
	employee Adam = { "Adam", 20012021, 12500.0 };

	printf("Employee info: Name: %s, hired on %d, salary: %f\n", Adam.name, Adam.hireDate, Adam.salary);

	employee random;
	printf("Type in the following employee data:\n");
	printf("Name: ");
	fgets(random.name, 39, stdin);
	random.name[strlen(random.name)-1] = 0x0;
	printf("Hire date: ");
	scanf_s("%d", &random.hireDate);
	getchar();
	printf("Salary: ");
	scanf_s("%f", &random.salary);
	getchar();

	printf("Employee info: Name: %s, hired on %d, salary: %f\n", random.name, random.hireDate, random.salary);

	return 0;
}

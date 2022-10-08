#include <stdio.h>
#include <stdlib.h>


void ptrSquare(int*);

int main()
{
	int x = 0;
	printf("Type an int to square: ");
	scanf_s("%d", &x);
	fflush(stdin);
	printf("x = %d ", x);
	ptrSquare(&x);
	printf("x^2 = %d\n", x);
	return 0;
}

void ptrSquare(int* arg)
{
	*arg = (*arg) * (*arg);
	return;
}
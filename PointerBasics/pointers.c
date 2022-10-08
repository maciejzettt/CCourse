#include <stdio.h>


int main()
{
	int number = 12;
	int* pointer = NULL;

	pointer = &number;

	printf("Address: %p, Value: %p, Dereference: %d, Size: %u", (void*)&pointer, pointer, *pointer, sizeof(*pointer));
	return 0;
}
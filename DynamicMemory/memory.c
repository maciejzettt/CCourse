#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned size;
	printf("Type in the maximum number of characters to read: ");
	scanf_s("%u", &size);
	getchar(); //Flushing stdin to avoid blocking it by a stuck newline.
	printf("\n");

	//Allocating memory for specified size of string. Using calloc to zero all bytes.
	char* string = calloc(size + 1, sizeof(char));
	if (string == NULL)
	{
		printf("\n --- Error allocatig memory. Program will exit.\n");
		exit(1);
	}

	printf("Enter your string: ");
	fgets(string, size, stdin);
	string[strlen(string) - 1] = '\0';
	printf("You have entered [%s].\n", string);

	free(string);
	string = NULL;
	return 0;
}
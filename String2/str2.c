#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int length = 0;
	char text[100];
	printf("Enter text: ");
	fgets(text, 100, stdin);
	length = strlen(text);
	char * reverse = malloc(length + 1);
	for (int pos = 0; pos < length; pos++)
	{
		reverse[pos] = text[length - pos - 1];
	}
	reverse[length] = '\0';
	printf("%s", reverse);
	free(reverse);
	return 0;
}
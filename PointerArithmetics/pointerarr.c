#include <stdio.h>
#include <stdlib.h>

int stringlength(char*);

int main(void)
{
	char temp[200];
	printf("Input string: ");
	fgets(temp, 199, stdin);
	printf("String [%s] has length %d", temp, stringlength(temp));
	return 0;
}

int stringlength(char* in)
{
	char* t = in;
	while (*t)
		t++;
	int r = t - in;
	return r;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned length(char*);
unsigned cat(char*, char*);
int comp(char*, char*);


int main(void)
{
	char zdanie1[] = "To jest jakies zdanie. ";
	char zdanie2[] = "A to kolejne.";
	printf("%d\n", length(zdanie1));
	char* zdanie3 = cat(zdanie1, zdanie2);
	printf("%s\n", zdanie3);
	printf("Zdanie1 vs Zdanie2: %d\n", comp(zdanie1, zdanie2));
	printf("Zdanie1 vs zdanie3: %d\n", comp(zdanie1, zdanie3));
	printf("Zdanie2 vs Zdanie2: %d\n", comp(zdanie2, zdanie2));
	printf("Zdanie3 vs zdanie1: %d\n", comp(zdanie3, zdanie1));
	return 0;
}

unsigned length(char* str)
{
	unsigned pos = 0;
	if (str != NULL)
	{
		while (str[pos] != 0)
			pos++;
	}
	return pos;
}

unsigned cat(char* str1, char* str2)
{
	unsigned len1 = length(str1) * sizeof(char);
	unsigned len2 = length(str2) * sizeof(char);
	size_t size = (len1 + len2 + 1);
	char* temp = malloc(size);
	if (temp != NULL)
	{
		memcpy(temp, str1, len1);
		memcpy((temp + len1), str2, len2);
		temp[len1 + len2] = 0;
	}
	return temp;
}

int comp(char* str1, char* str2)
{
	int cres = 0;
	unsigned index = 0;
	unsigned len1 = length(str1);
	unsigned len2 = length(str2);
	unsigned max = (len1 > len2) ? len2 : len1;
	while (index <= max)
	{
		if (str1[index] != str2[index])
		{
			cres = (str1[index] > str2[index]) ? 1 : -1;
			break;
		}
		else if ((index == max) && (len1 == len2))
		{
			cres = 0;
			break;
		}
		else if ((index == max) && (len1 != len2))
		{
			cres = (len1 > len2) ? 1 : -1;
			break;
		}
		else
		{
			index++;
			continue;
		}
	}
	return cres;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	unsigned numberOfStrings = 0;
	printf("How many strings do you want to enter?: ");
	scanf_s("%u", &numberOfStrings);
	fflush(stdin);
	unsigned * list = malloc(numberOfStrings * sizeof(unsigned));

	for (unsigned i = 0; i < numberOfStrings; i++)
	{
		char temp[200];
		printf("\nString %d: ", i + 1);
		fgets(temp, 199, stdin);
		size_t len = strlen(temp);
		list[i] = malloc(len + 1);
		memcpy(list[i], temp, len + 1);
	}

#ifdef _TEST
	for (unsigned i = 0; i < numberOfStrings; i++)
	{
		printf("\nString %d: %s", i + 1, (char*)list[i]);
		free(list[i]);
	}
	free(list);
#endif

	// SORTING
	for (unsigned run = 1; run < (numberOfStrings); run++)
	{
		for (unsigned position = 0; position < (numberOfStrings - run); position++)
		{
			unsigned temp = 0;
			int comp = strcmp((char*)list[position], (char*)list[position+1]);
			if (comp > 0)
			{
				temp = list[position + 1];
				list[position + 1] = list[position];
				list[position] = temp;
			}
		}
	}

	printf("%s", "SORTED LIST:\n");

	for (unsigned i = 0; i < numberOfStrings; i++)
	{
		printf("\nString %d: %s", i + 1, (char*)list[i]);
	}

	return 0;
}
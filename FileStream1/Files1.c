#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * hFile;
	int error = fopen_s(&hFile, "C:/temp/example.txt", "r");

	int count = 0;
	if (error)
		perror("Error opening file");
	else
	{
		char temp = 0;
		char newline = '\n';
		temp = fgetc(hFile);
		while (temp != -1)
		{
			if (temp == newline)
				count++;
			temp = fgetc(hFile);
		}
		printf("The file consists of %d lines", count + 1);
		fclose(hFile);
	}
	return 0;
}
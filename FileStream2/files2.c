#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char ch = 0;
	FILE* hFileOriginal = NULL;
	int errorOriginal = fopen_s(&hFileOriginal, "C:/temp/kurs.txt", "r");
	

	if (errorOriginal)
	{
		perror("Error opening original file");
	}
	else
	{
		FILE* hFileTemp = NULL;
		int errorTemp = fopen_s(&hFileTemp, "C:/temp/kurstemp.txt", "w");
		if (errorTemp)
		{
			perror("Error creating temp file");
		}
		else
		{
			while ((ch = fgetc(hFileOriginal)) != EOF)
			{
				fputc(toupper(ch), hFileTemp);
			}
			fclose(hFileTemp);
			hFileTemp = NULL;
			fclose(hFileOriginal);
			hFileOriginal = NULL;
			remove("C:/temp/kurs.txt");
			rename("C:/temp/kurstemp.txt", "C:/temp/kurs.txt");
			errorOriginal = fopen_s(&hFileOriginal, "C:/temp/kurs.txt", "r");
			if (errorOriginal)
			{
				perror("Error reading from file");
			}
			else
			{
				char line[256];
				while (fgets(line, 255, hFileOriginal) != NULL)
					fputs(line, stdout);
				fclose(hFileOriginal);
			}
				
		}
		if (hFileOriginal)
			fclose(hFileOriginal);
	}


	return 0;
}
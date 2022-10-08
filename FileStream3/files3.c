#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* hFile = NULL;
	int error = fopen_s(&hFile, "C:/temp/kurs.txt", "r");
	if (error)
	{
		perror("Error accessing the file");
		puts("The program will terminate");
	}
	else
	{
		char c;
		long beginning = ftell(hFile);
		int seekerror;
		fseek(hFile, -1, SEEK_END);
		putchar(fgetc(hFile));

		while (1)
		{
			if ((seekerror = fseek(hFile, -2, SEEK_CUR)) == 0)
			{
				if (ftell(hFile) == beginning)
				{
					c = '#';
					c = fgetc(hFile);
					putchar(c);
					/*if (c == '\n')
						fseek(hFile, -1, SEEK_CUR);*/
					break;
				}
				c = fgetc(hFile);
				putchar(c);
				if (c == '\n')
					fseek(hFile, -1, SEEK_CUR);

			}
			else
			{
				perror("Error seeking file");
				printf("errorno: %d \n", seekerror);
				break;
			}
		}
		fclose(hFile);
		hFile = NULL;
	}
	return 0;
}
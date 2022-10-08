#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define CLS system("cls")


char table[10] = {"0---------"};

void	drawTable(char* arr);
int		putIntoTable(char* arr, char what, int pos);
int		isFinished(char* arr);


int main(void)
{
	unsigned turn = 1;
	char who = 0x58;
	int where = 0;

	do
	{
		who = (turn % 2 == 1) ? 0x58 : 0x4f;
		char str[4];
		CLS;
		if (turn <= 9)
		{
			printf("\tTicTacToe\n Turn of %c.\n\n", who);
			drawTable(table);
			do
			{
				where = 0;
				printf("\n%c, your position of choice is: ", who);
				fgets(str, 3, stdin);
				sscanf_s("%d", &where);
			} while (putIntoTable(table, who, where));
			turn++;
		}
		else
		{
			printf("A draw!");
			break;
		}

	} while (!isFinished(table));
	if (turn <= 9)
	{
		CLS;
		drawTable(table);
		printf("WINNER: %c!\n", who);
	}

	return 0;
}

void	drawTable(char* arr)
	{
	printf("%s\n", arr);
		printf("|1    |2    |3    |\n");
		printf("|  %c  |  %c  |  %c  |\n", arr[1], arr[2], arr[3]);
		printf("|     |     |     |\n");
		printf("|=====|=====|=====|\n");
		printf("|4    |5    |6    |\n");
		printf("|  %c  |  %c  |  %c  |\n", arr[4], arr[5], arr[6]);
		printf("|     |     |     |\n");
		printf("|=====|=====|=====|\n");
		printf("|7    |8    |9    |\n");
		printf("|  %c  |  %c  |  %c  |\n", arr[7], arr[8], arr[9]);
		printf("|     |     |     |\n");
		printf("|=====|=====|=====|\n");
		return;
	}

int	putIntoTable(char* arr, char what, int pos)
	{

		if ((pos >= 1) && (pos <= 9) && (arr[pos] == '-'))
		{
			arr[pos] = what;
			return 0;
		}
		else
		{
			printf("Wrong position!\n");
			return 1;
		}
	}

int		isFinished(char* arr)
{
	if ((arr[1]!= '-' && arr[1] == arr[2] && arr[2] == arr[3]) ||
		(arr[4] != '-' && arr[4] == arr[5] && arr[5] == arr[6]) ||
		(arr[7] != '-' && arr[7] == arr[8] && arr[8] == arr[9]) ||
		(arr[1] != '-' && arr[1] == arr[4] && arr[4] == arr[7]) ||
		(arr[2] != '-' && arr[2] == arr[5] && arr[5] == arr[8]) ||
		(arr[3] != '-' && arr[3] == arr[6] && arr[6] == arr[9]) ||
		(arr[1] != '-' && arr[1] == arr[5] && arr[5] == arr[9]) ||
		(arr[3] != '-' && arr[3] == arr[5] && arr[5] == arr[7]))
		return 1;
	else
		return 0;
}
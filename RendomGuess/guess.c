
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <stdbool.h>

#define MAX_NUM 20

int num = 0;
int input = 0;

int main()
{
	srand(time(NULL));
	num = rand() % (MAX_NUM + 1);
	bool guessed = false;

	for (unsigned attempt = 1; attempt <= 5; attempt++)
	{
		while (true) //input loop
		{
			printf("\nAttempt %d\nGive a number from 0 to %d: ", attempt, MAX_NUM);
			scanf_s("%d", &input);
			printf("\n");
			if (input >= 0 && input <= MAX_NUM)	// if input is within range
				break;								// then exit input loop
			else									// else input is out of range - notify user
				printf("The number must be at least 0 and at most %d!\n", MAX_NUM);
		}
		// test if guess is right
		if (input == num)							// if it is correct, congratulate and exit loop
		{
			printf("\n\n=== YOU HAVE GUESSED: %d IS CORRECT!\n\n", input);
			guessed = true;
			break;
		}
		else										// else notify user and continue
		{
			printf("Your guess is %s than the number.\n", (input < num) ? "smaller" : "bigger");
			continue;
		}
	}

	if (!guessed)									// if attempts ran out or loop was broken, test if not guessed
	{
		printf("You have not guessed in all attempts. Sorry.\n");
	}

	return 0;
}
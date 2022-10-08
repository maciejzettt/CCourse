#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 20

time_t t = 0;
srand();
int randomNumber = 0;
randomNumber = (rand() % (MAX_NUMBER + 1));

int main() {
	printf("Wynik: %d", randomNumber);

	return 0;
} 
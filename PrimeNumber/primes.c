#include <stdio.h>
#define MAX 100
#define VARIANT 1

#if VARIANT == 1
int main()
{
	unsigned primes[40] = {[0] = 2, [1] = 3 };

	unsigned primePos = 2;
	unsigned currentNum = 5;


	while (currentNum <= MAX && primePos < 40)
	{
		printf("Pos %2d: ", primePos);
		printf("%d ", currentNum);
		unsigned divisors = 0;
		for (unsigned i = 1; i < primePos; i++)
		{
			if (currentNum % primes[i] == 0)
			{
				divisors = 1;
				break;
			}
			else continue;
				
		}
		if (divisors)
		{
			//printf("(is divided by something) ");
			currentNum += 2;
			continue;
		}
		else
		{
			printf("(is a prime) \n");
			primes[primePos] = currentNum;
			currentNum += 2;
			primePos++;
			continue;
		}
	}
}
#endif

#include <stdio.h>
#include <stdlib.h>
#define PRECISION 0.00001

int fnGCD(int, int);
double fnABS(double);
double fnSQRT(double);
 

int main(void)
{
	//printf("\n GCD of 256 and 24 is %d", fnGCD(256, -24));
	//printf("\n ABS of 7 is %f", fnABS(7));
	
	fnSQRT(10000);
	return 0;
}

int fnGCD(int x, int y)
{
	x = fnABS(x);
	y = fnABS(y);
	int higher = (x > y) ? x : y;
	int lower = (x > y) ? y : x;
	int store = lower;

	/*if ((higher % lower) == 0)
			return lower;
	else
	{*/
		for (unsigned i = lower; i >= 0; i--)
		{
			if ((higher % i == 0) & (lower % i == 0))
			{
				store = i;
				break;
			}
			else
			{
				continue;
			}
		}
	/*}*/

	return store;
}

double fnABS(double x)
{
	return (x < 0) ? -x : x;
}

double fnSQRT(double x)
{
	if (x < 0)
	{
		printf("\nA negative value was used!\n");
		return -1;
	}
	else if (x == 0)
	{
		return 0.0;
	}
	else if (x > 1)		//general case for x > 1
	{
		double x0 = 1.0;
		unsigned iteration = 1;
		printf("Computating square root of %f:\n", x);
		
		double error = (x - x0 * x0) / x;
		while (fnABS(error) > PRECISION) 
		{
			x0 = (x0 + x / x0)  / 2;
			printf("\tIteration %d, value: %.12f, rel. error: %.12f\n", iteration, x0, error);
			iteration++;
			error = (x - x0 * x0) / x;
		} 
		printf("\tFINAL: %.12f", x0 * (1 + error/2));
		return x0 * (1 + error/2);
	}
	else
	{					// case for 0 < x < 1
		double x0 = 1.0;
		unsigned iteration = 1;
		printf("Computating square root of %f:\n", x);

		double error = (x - x0 * x0) / x;
		while (fnABS(error) > PRECISION)
		{
			x0 = (x0 + x * error);
			printf("\tIteration %d, value: %.12f, rel. error: %.12f\n", iteration, x0, error);
			iteration++;
			error = (x - x0 * x0) / x;
			//if (iteration == 100)
			//	return -1;
		}
		printf("\tFINAL: %.12f", x0 * (1 + error/2));
		return x0 * (1 + error/2);
	}
	return -1;
}


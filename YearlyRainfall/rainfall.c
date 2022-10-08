#include <stdio.h>

typedef unsigned char small;

int main()
{
	double data[5][12] =
	{	//	1		2		3		4		5		6		7		8		9		10		11		12
		{	13.5,	22.7,	18.3,	19.7,	14.2,	11.9,	8.1,	7.3,	13.5,	19.2,	19.7,	15.2	},
		{	12.5,	23.7,	19.3,	19.7,	14.2,	11.9,	8.1,	7.3,	13.5,	19.2,	19.7,	15.2	},
		{	12.5,	22.7,	18.3,	20.7,	14.2,	11.9,	8.1,	7.3,	13.5,	19.2,	19.7,	15.2	},
		{	12.5,	22.7,	18.3,	19.7,	15.2,	11.9,	8.1,	7.3,	13.5,	19.2,	19.7,	15.2	},
		{	12.5,	22.7,	18.3,	19.7,	14.2,	12.9,	8.1,	7.3,	13.5,	19.2,	19.7,	15.2	}
	};

	unsigned startYear = 2010;

	//for (unsigned y = 0; y < 5; y++)	// DIAGNOSTIC PRINT
	//{
	//	printf("%d YEAR DATA: \n", startYear + y);

	//	for (unsigned m = 0; m < 12; m++)
	//	{
	//		printf("Month %2d: %2.1f\n", m + 1, data[y][m]);
	//	}
	//	printf("\n");
	//}

	// YEARLY SUM

	printf("\nYearly rainfall statistics:\n");
	float sum[5] = { 0.0 };
	float sumsum = 0.0;
	for (small y = 0; y < 5; y++)
	{
		for (small m = 0; m < 12; m++)
			sum[y] += data[y][m];
		printf("%d total rainfall: %4.1f\n", startYear + y, sum[y]);
		sumsum += sum[y];
	}
	
	printf(" Average yearly rainfall: %4.1f\n", sumsum / 5);

	//MONTHLY AVERAGE

	printf("\nMonths startistics:\n");
	float month_sum[12] = { 0.0 };
	for (small m = 0; m < 12; m++)
	{
		for (small y = 0; y < 5; y++)
			month_sum[m] += data[y][m];
		printf("%d average rainfall: %4.1f\n", m + 1, month_sum[m]/5);
		
	}

	return 0;
}
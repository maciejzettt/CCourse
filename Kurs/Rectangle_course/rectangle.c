#include <stdio.h>
#include <stdlib.h>

double width = 0.0, height = 0.0, perim = 0.0, area = 0.0;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Invalid number of arguments: %d, specify width and heigth!\n", argc);
		return EXIT_FAILURE;
	}
	else
	{
		width = strtod(argv[1], NULL);
		height = strtod(argv[2], NULL);
		area = width * height;
		perim = 2 * (width + height);
		printf("For a rectangle of width %f and height %f:\nArea equals %f\nPerimeter equals %f", width, height, area, perim);
		return EXIT_SUCCESS;
	}
} 
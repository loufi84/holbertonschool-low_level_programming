#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/**
 * main - Entry point
 * Description: This program compare n random and return 0
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%zu is positive\n", n);
	}
	else if (n == 0)
	{
		printf("0 is zero\n");
	}
	else
	{
		printf("%zu is negative\n", n);
	}
	return (0);
}

#include <stdio.h>

/**
 * main - Entry point
 * Description: This function will list all natural
 * numbers multiples of 3 and 5 and computes there
 * sums below 1024 excluded
 * Return: int
 */

int main(void)
{
	int i = 0;
	int sum = 0;

	for (; i < 1024; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			sum += i;
		}
	}

	printf("%d\n", sum);

	return (0);
}

#include <stdio.h>

/**
 * main - Entry point
 * Description: This program will output every number from 1 to 100
 * replacing multiples of 3 by Fizz and multiples of 5 by Buzz
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i = 1;

	for (; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz ");
		}
		else
		{
			printf("%d ", i);
		}
	}
	return (0);
}

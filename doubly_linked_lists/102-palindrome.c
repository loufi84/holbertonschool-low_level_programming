#include <stdio.h>

/**
 * is_pal - A function that checks if a number is a palindrome
 *
 * @n: The number to check
 *
 * Return: The palindrome
 */

int is_pal(int n)
{
	int rev = 0, origin = n, digit;

	while (n > 0)
	{
		digit = n % 10;
		rev = rev * 10 + digit;
		n /= 10;
	}
	return (rev == origin);
}

/**
 * save_res - A function that saves the result to a file
 *
 * @n: The number to save
 *
 * Return: Nothing
 */

void save_res(int n)
{
	FILE *file = fopen("102-result", "w");

	if (file)
	{
		fprintf(file, "%d", n);
		fclose(file);
	}
}

/**
 * main - Entry point
 *
 * Return: 0 for success
 */

int main(void)
{
	int max_pal = 0, a, b, prod;

	for (a = 999; a >= 100; a--)
	{
		for (b = a; b >= 100; b--)
		{
			prod = a * b;

			if (is_pal(prod) && prod > max_pal)
				max_pal = prod;
		}
	}
	save_res(max_pal);

	return (0);
}

#include "main.h"
#include <stdlib.h>

/**
 * is_dig - Checks if a char is a digit
 * @n: The char to check
 * Return: The digit
 */

int is_dig(int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * is_all_zeroes - Check for multiple zeroes
 * @num: The number to check
 * Return: 1 for success, 0 is all zeroes
 */

int is_all_zeroes(char *num)
{
	int i = 0;

	while (num[i])
	{
		if (num[i] != '0')
			return (0);

		i++;
	}

	return (1);
}

/**
 * _strlen - Calculate the length of a string
 * @str: The string to calculate
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * _calloc - Allocate memory and initialize it at 0
 * @nmemb: The number of elements
 * @size: The size of the array
 * Return: A pointer to the allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * print - Print the result of the multiplication
 * @res: The result to print
 * @len: The length of the result
 * Return: Nothing
 */

void print(int *res, int len)
{
	int i, start = 0;

	while (start < len && res[start] == 0)
		start++;

	if (start == len)
		_putchar('0');

	else
	{
		for (i = start; i < len; i++)
			_putchar(res[i] + '0');
	}
	_putchar('\n');
}

/**
 * print_err - Print the error message and exit program
 * Return: Nothing
 */

void print_err(void)
{
	char *err = "Error\n";
	int i;

	for (i = 0; err[i]; i++)
		_putchar(err[i]);
	exit(98);
}

/**
 * mult - Multiplicate the numbers
 * @num1: The 1st number
 * @num2: The second number
 * Return: Nothing
 */

void mult(char *num1, char *num2)
{
	int len1, len2, i, j, *res;
	unsigned long n1, n2, sum;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	res = _calloc(len1 + len2, sizeof(int));
	if (res == NULL)
		print_err();

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			sum = res[i + j + 1] + (n1 * n2);
			res[i + j] += sum / 10;
			res[i + j + 1] = sum % 10;
		}
	}

	print(res, len1 + len2);
	free(res);
}

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The value of arguments
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	char *n1, *n2;
	int i;

	if (argc != 3)
		print_err();

	n1 = argv[1];
	n2 = argv[2];

	if (n1[0] == '\0' || n2[0] == '\0')
	{
		print_err();
	}
	if (is_all_zeroes(n1) || is_all_zeroes(n2))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 0; n1[i]; i++)
		if (!is_dig(n1[i]))
			print_err();

	for (i = 0; n2[i]; i++)
		if (!is_dig(n2[i]))
			print_err();

	if (is_all_zeroes(n1) || is_all_zeroes(n2))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	if ((n1[0] == '0' && n1[1] != '\0') || (n2[0] == '0' && n2[1] != '\0'))
		print_err();
	mult(n1, n2);
	return (0);
}

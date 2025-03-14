#include "main.h"
#include <stdlib.h>

/**
 * is_dig - Checks if a char is a digit
 * @n: The char to check
 * Return: 1 if it's a digit, 0 otherwise
 */
int is_dig(char n)
{
	return (n >= '0' && n <= '9');
}

/**
 * is_all_zeroes - Check if a string consists of only zeroes
 * @num: The string to check
 * Return: 1 if all zeroes, 0 otherwise
 */
int is_all_zeroes(char *num)
{
	while (*num)
	{
		if (*num != '0')
			return (0);
		num++;
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
 * print_result - Print the result of the multiplication
 * @res: The result array
 * @len: The length of the result
 */
void print_result(int *res, int len)
{
	int i = 0;

	while (i < len && res[i] == 0)
		i++;

	if (i == len)
	{
		_putchar('0');
	}
	else
	{
		for (; i < len; i++)
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
 * multiply - Multiply two large numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j, n1, n2, sum;

	if (result == NULL)
		print_err();

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_result(result, len1 + len2);

	free(result);
}

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The value of arguments
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i;

	if (argc != 3)
		print_err();

	num1 = argv[1];
	num2 = argv[2];

	if (num1[0] == '\0' || num2[0] == '\0')
		print_err();

	for (i = 0; num1[i]; i++)
		if (!is_dig(num1[i]))
			print_err();

	for (i = 0; num2[i]; i++)
		if (!is_dig(num2[i]))
			print_err();

	if (is_all_zeroes(num1) || is_all_zeroes(num2))
		print_err();

	multiply(num1, num2);

	return (0);
}

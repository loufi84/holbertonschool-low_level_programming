#include "main.h"
#include <stdlib.h>

/**
 * is_digit - Checks if a character is a digit
 * @c: The character to check
 * Return: 1 if it's a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * all_zeroes - Checks if a string consists of only zeroes
 * @str: The string to check
 * Return: 1 if all zeroes, 0 otherwise
 */
int all_zeroes(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

/**
 * str_length - Calculates the length of a string
 * @str: The string to measure
 * Return: The length of the string
 */
int str_length(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

/**
 * print_error - Prints an error message and exits the program
 */
void print_error(void)
{
	char *error_msg = "Error\n";

	while (*error_msg)
		_putchar(*error_msg++);
	exit(98);
}

/**
 * print_result - Prints the result of the multiplication
 * @result: The result array
 * @size: The size of the result array
 */
void print_result(int *result, int size)
{
	int i = 0;

	// Skip leading zeroes
	while (i < size && result[i] == 0)
		i++;

	if (i == size)
	{
		_putchar('0');
	}
	else
	{
		for (; i < size; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
}

/**
 * multiply_strings - Multiplies two large numbers represented as strings
 * @num1: The first number as a string
 * @num2: The second number as a string
 */
void multiply_strings(char *num1, char *num2)
{
	int len1 = str_length(num1);
	int len2 = str_length(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j;

	if (!result)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			int sum = digit1 * digit2 + result[i + j + 1];

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_result(result, len1 + len2);
	free(result);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, exits with error code otherwise
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	if (all_zeroes(num1) || all_zeroes(num2))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	for (i = 0; num1[i]; i++)
		if (!is_digit(num1[i]))
			print_error();

	for (i = 0; num2[i]; i++)
		if (!is_digit(num2[i]))
			print_error();

	multiply_strings(num1, num2);

	return (0);
}

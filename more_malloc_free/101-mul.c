#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit_str - Check if a string is a number
 * @str: The string to check
 * Return: 1 if the string is a number
 */

/* Helper function to check if the string is composed of digits*/
int is_digit_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			/* If a char is not a digit return 0 */
			return (0);
	}
	return (1);
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string from which the length is calculated
 * Return: Int length of string
 */

int _strlen(char *s)
{
	int len = 0;
	while (s[len])
		len++;

	return (len);
}

/**
 * init_result - Initialize the result (helper function)
 * @res: The result of multiplication
 * @size: The size of the number
 * Return: Nothing
 */

void init_result(int *res, int size)
{
	int i;

	for (i = 0; i < size; i++)
		res[i] = 0;
}

/**
 * perform_mult - Perform the arithmetic calculations
 * @num1: The first number
 * @num2: The second number
 * @res: The result of multiplication
 * @len1: The length of the 1st number
 * @len2: The length of the 2nd number
 * Return: Nothing
 */

void perform_mult(char *num1, char *num2, int *res, int len1, int len2)
{
	int i, j, dig1, dig2, pos1, pos2, sum, prod;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			dig1 = num1[i] - '0';
			dig2 = num2[j] - '0';
			prod = dig1 * dig2;
			pos1 = i + j;
			pos2 = i + j + 1;
			sum = prod + res[pos2];
			res[pos2] = sum % 10;
			res[pos1] += sum / 10;
		}
	}
}

/**
 * handle_carries - Handle the carries after the multiplication
 * @res: The result from which we need a carry
 * @size: The size of the number
 * Return: Nothing
 */

void handle_carries(int *res, int size)
{
	int i;

	for (i = size - 1; i > 0; i--)
	{
		if (res[i] >= 10)
		{
			res[i - 1] += res[i] / 10;
			res[i] %= 10;
		}
	}
}

/**
 * print_prod - Helper function that print the result
 * of the multiplication
 * @res: The result to be printed
 * @size: The size of the result
 * Return: Nothing
 */

void print_prod(int *res, int size)
{
	int start = 0, i;

	while (start < size && res[start] == 0)
		start++;

	if (start == size)
		_putchar('0');

	else
	{
		for (i = start; i < size; i++)
			_putchar(res[i] + '0');

		_putchar('\n');
	}
}

/**
 * multiply - Helper function to multiply two large numbers
 * @num1: The first number
 * @num2: The second number
 * Return: The result of num1 * num2
 */

/* Implementing a function to multiply two large numbers */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int tot_len = len1 + len2;
	int *res = malloc(tot_len * sizeof(int));

	if (!res)
		exit(98);

	init_result(res, tot_len);
	perform_mult(num1, num2, res, len1, len2);
	handle_carries(res, tot_len);
	print_prod(res, tot_len);
	free(res);
}
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: The values of said arguments
 * Return: Always 0 for success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	multiply(argv[1], argv[2]);

	return (0);
}

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
		if (!isdigit(str[i]))
		{
			/* If a char is not a digit return 0 */
			return (0);
		}
	}
	return (1);
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
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int i, j, dig1, dig2, prod, pos1, pos2, sum, start;
	int *res = (int *)malloc((len1 + len2) * sizeof(int));

	if (res == NULL)
		exit(98);
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;
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
			res[pos2] = sum % 10; /* Store dig in current position */
			res[pos1] += sum / 10; /* Carry the next higher position */
		}
	}
	start = 0;
	while (start < len1 + len2 && res[start] == 0)
		start++;

	if (start == len1 + len2)
		printf("0\n");
	else
	{
		for (i = start; i < len1 + len2; i++)
		{
			printf("%d", res[i]);
		}
		printf("\n");
	}
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

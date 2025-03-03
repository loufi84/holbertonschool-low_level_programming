#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: values of said arguments
 * Return: 0 for success, 1 for failure
 */

int main(int argc, char *argv[])
{
	int index, check;
	int sum = 0;

	for (index = 1; index < argc; index++)
	{
		for (check = 0; argv[index][check] != '\0'; check++)
		{
			if (!isdigit(argv[index][check]))
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[index]);

	}

	printf("%d\n", sum);

	return (0);
}

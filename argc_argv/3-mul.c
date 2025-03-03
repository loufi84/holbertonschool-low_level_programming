#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: number of parameters
 * @argv: values of said parameters
 * Description: This program will multiply two numbers and
 * print the result. If it does not receives two int,
 * it will print "Error" and return 1
 * Return: 0 for success, 1 for failure
 */

int main(int argc, char *argv[])
{
	int res = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	res = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", res);

	return (0);
}

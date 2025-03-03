#include <stdio.h>

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: value of said arguments
 * Description: This program womm prints all
 * arguments it receives, including the name
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int index;

	for (index = 0; index < argc; index++)
	{
		printf("%s\n", argv[index]);
	}

	return (0);
}

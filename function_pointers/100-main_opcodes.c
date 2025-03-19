#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument value
 * Return: 0 for success, 1 if argc incorrect, 2 if bytes neg
 */

int main(int argc, char *argv[])
{
	int opc, i;
	int (*f_ptr)(int, char **) = main;
	unsigned char *opcodes = (unsigned char *)f_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	opc = atoi(argv[1]);

	if (opc < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < opc; i++)
		printf(i < opc - 1 ? "%02x " : "%02x", opcodes[i]);

	printf("\n");

	return (0);

}

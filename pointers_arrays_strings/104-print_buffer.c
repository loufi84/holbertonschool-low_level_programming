#include "main.h"
#include <stdio.h>

/**
 * print_hex - Print the hexadecimal representation of the buffer
 *
 * @b: The pointer to the buffer
 * @size: The size of the buffer
 * @start: The starting index to print from
 */
void print_hex(char *b, int size, int start)
{
	int j;

	for (j = 0; j < 10; j++)
	{
		if (start + j < size)
		{
			printf("%02x", (unsigned char)b[start + j]);

			if (j % 2 != 0)
			{
				printf(" ");
			}
		}
		else
		{
			printf("   ");
		}
	}
}

/**
 * print_char - Print the character representation of the buffer
 *
 * @b: The pointer to the buffer
 * @size: The size of the buffer
 * @start: The starting index to print from
 */
void print_char(char *b, int size, int start)
{
	int j;
	char c;

	for (j = 0; j < 10; j++)
	{
		if (start + j < size)
		{
			c = b[start + j];
			printf("%c", (c >= 32 && c <= 126) ? c : '.');
		}
	}
}

/**
 * print_buffer - Print a buffer
 *
 * @b: The pointer to the buffer
 * @size: The size of the buffer
 *
 * Description: This function will print a buffer of a given size
 * in hexadecimal and character format.
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%8.8x: ", i);
		print_hex(b, size, i);
		printf(" ");
		print_char(b, size, i);
		printf("\n");
	}
}

#include "main.h"

/**
 * print_chessboard - print a chessboard
 * @a: The chessboard to print
 * Return: void
 */

void print_chessboard(char (*a)[8])
{
	int index = 0;
	int check = 0;

	for (index = 0; index < 8; index++)
	{
		for (check = 0; check < 8; check++)
		{
			_putchar(a[index][check]);
		}
		_putchar('\n');
	}
}

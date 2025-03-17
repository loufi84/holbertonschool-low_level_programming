#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - Prints a name
 * @name: The name to print
 * @f: The function pointer
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		return;

	if (name == NULL)
		return;

	f(name);
}

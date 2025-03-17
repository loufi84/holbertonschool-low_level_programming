#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything
 * @format: The format which need a print
 * Return: Nothing
 */

void print_all(const char * const format, ...)
{
	va_list(args);
	const char *str, *s = "";
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", s,  va_arg(args, int));
				break;

			case 'i':
				printf("%s%i", s,  va_arg(args, int));
				break;

			case 'f':
				printf("%s%f", s,  va_arg(args, double));
				break;

			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", s, str);
				break;

			default:
				i++;
				continue;
		}
		s = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}

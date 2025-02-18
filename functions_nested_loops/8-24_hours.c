#include "main.h"

/**
 * jack_bauer - print all 24 hours of Jack Bauer
 * Description: this function prints all 24h of Jack Bauer
 * Return: Every minute in 24 hours
 */

void jack_bauer(void)
{
	int hours, minutes;

	for (; hours < 24; hours++)
	{
		for (; minutes < 60; minutes++)
		{

			_putchar('0' + (hours / 10));
			_putchar('0' + (hours % 10));
			_putchar(':');

			_putchar('0' + (minutes / 10));
			_putcahr('0' + (minutes % 10));
			_putchar('\n');
		}

	}
}

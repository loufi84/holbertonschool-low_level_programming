#include "main.h"

/**
 * _atoi - convert a string to an itnt
 * @s: sring to convert to int
 * Return: int
 */

int _atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;
	int sign = 1;
	int fnd_dig = 0;

	while (s[i] == ' ')
	{
		i++;
	}


	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			fnd_dig = 1;
		}
		else if (fnd_dig)
		{
			break;
		}

		i++;
	}

	if (!fnd_dig)
		return (0);

	return (num * sign);
}

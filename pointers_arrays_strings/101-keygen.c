#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* target = 2772 (Oxad4) */

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int sum = 0;
	char password[100];
	int index = 0;
	int rand_char;

	srand(time(0));

	while (sum < 2772 - 126)
	{
		rand_char = (rand() % 94) + 33;
		password[index] = rand_char;
		sum += rand_char;
		index++;
	}

	password[index++] = 2772 - sum;
	password[index] = '\0';

	printf("%s\n", password);

	return (0);
}

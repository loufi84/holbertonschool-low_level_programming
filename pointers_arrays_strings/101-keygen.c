#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET_CHECKSUM 0xAD4

/**
 * generate_password - Generates a random password
 * @password: Pointer to the buffer where passwd is stored
 * @length: Length of the passwd to generate
 * Description: This function will generate a random password
 * whose ASCII values sum up to 2772
 * Return: void
 */

void generate_password(char *password, int length)
{
	int index, sum = 0;

	/* Seed random number generator with current tim */
	srand(time(NULL));

	for (index = 0; index < length - 1; i++)
	{
		password[i] = rand() % 94 + 33;
		sum += password[i];
	}

	int last_char = TARGET_CHECKSUM - sum;

	while (last_char < 33 || last_char > 126)
	{
		sum = 0;
		for (i = 0; i < length - 1; i++)
		{
			password[i] = rand() % 94 + 33;
			sum += password[i];
		}
		last_char = TARGET_CHECKSUM - sum;
	}

	password[length - 1] = last_char;
	password[length] = '\0';
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char password[100];
	int length = 10;

	generate_password(password, length);

	printf("Generated password: %s\n", password);

	return (0);
}

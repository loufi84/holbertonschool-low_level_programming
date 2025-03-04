#include <stdio.h>
#include <stdlib.h>

/**
 * check_min_coin - compute the minimu number of coins
 * @value: The amount of money
 * Return: The min number of coins
 */

int check_min_coin(int value)
{
	int coins = 0;
	int coin_den[] = {25, 10, 5, 2, 1};
	int num = sizeof(coin_den) / sizeof(coin_den[0]);
	int index = 0;

	for (index = 0; index < num; index++)
	{
		while (value >= coin_den[index])
		{
			value -= coin_den[index];
			coins++;
		}
	}

	return (coins);
}


/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: values of said arguments
 * Description: This program will output the minimum
 * number of coins to make change for an amount of money
 * Return: int
 */

int main(int argc, char *argv[])
{
	int coins;
	int value;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	value = atoi(argv[1]);

	if (value < 0)
	{
		printf("0\n");
		return (0);
	}

	coins = check_min_coin(value);
	printf("%d\n", coins);

	return (0);
}

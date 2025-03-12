#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_words - Function that counts the words in arguments
 * @str: The string to check
 * Return: The number of words in a string
 */

int count_words(char *str)
{
	int i;
	int nb = 0;
	int in = 0;

	if (str[0] == '\0' || str == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in)
		{
			in = 1;
			nb++;
		}
		else if (str[i] == ' ')
		{
			in = 0;
		}
	}
	return (nb);
}

/**
 * strtow - Split string in words
 * @str: The string to split
 * Return: A pointer to str
 */

char **strtow(char *str)
{
	char **word;
	int nb_words, i, j, word_len, m, k = 0;

	if (str[0] == '\0' || str == NULL)
	{
		return (0);
	}

	nb_words = count_words(str);

	word = malloc(sizeof(char *) * (nb_words + 1));
	if (word == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0' && k < nb_words)
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}

		word_len = 0;
		while (str[i + word_len] != ' ' && str[i + word_len] != '\0')
		{
			word_len++;
		}

		word[k] = malloc(word_len + 1);
		if (word[k] == NULL)
		{
			for (m = 0; m < k; m++)
			{
				free(word[m]);
			}
			free(word);
			return (NULL);
		}
		for (j = 0; j < word_len; j++)
		{
			word[k][j] = str[i + j];
		}
		word[k][word_len] = '\0';

		i += word_len;
		k++;
	}

	word[k] = NULL;

	for (m = 0; m < k; m++)
	{
		free(word[m]);
	}
	free(word);

	return (word);
}

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

	if (str == NULL || str[0] == '\0')
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
 * word_count - Calculate the length of a word
 * @str: The string to extract words from
 * Return: int length for word
 */

int word_count(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
	{
		len++;
	}

	return (len);
	
}

/**
 * strtow - Split string in words
 * @str: The string to split
 * Return: A pointer to str
 */

char **strtow(char *str)
{
	char **word;
	int i = 0, j, k, word_len, word_nb;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}

	word_nb = count_words(str);
	if (word_nb == 0)
	{
		return (NULL);
	}

	word = malloc(sizeof(char *) * (word_nb + 1));
	if (word == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < word_nb; j++)
	{
		while (str[i] == ' ')
		{
			i++;
		}

		word_len = word_count(str + i);

		word[j] = malloc(sizeof(char) * (word_len + 1));
		if (word[j] == NULL)
		{
			for (k = 0; k < j; k++)
			{
				free(word[k]);
			}
			free(word);
			return (NULL);
		}

		for (k = 0; k < word_len; k++)
		{
			word[j][k] = str[i + k];
		}
		word[j][k] = '\0';

		i += word_len;
	}

	word[j] = NULL;

	return (word);
}

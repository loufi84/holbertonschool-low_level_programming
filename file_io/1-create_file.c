#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - A function that calculate the length of a string
 *
 * @str: The string to check
 *
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * create_file - A function that creates a file
 *
 * @filename: The name of the file
 * @text_content: The text to put in the file
 *
 * Return: 1 for success, -1 if fail
 */

int create_file(const char *filename, char *text_content)
{
	ssize_t file, len, bytes_w;

	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = _strlen(text_content);
		bytes_w = write(file, text_content, len);
		if (bytes_w == -1)
		{
			close(file);
			return (-1);
		}
	}

	close(file);

	return (1);
}

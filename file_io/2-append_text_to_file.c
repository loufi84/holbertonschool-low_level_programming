#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _strlen - A function that calculate the length of a string
 *
 * @str: The string to compute
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
 * append_text_to_file - Append text in a file
 *
 * @filename: The name of the file to modify
 * @text_content: The text to append to the file
 *
 * Return: 1 for success, -1 for failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t file, bytes_w;
	int size;

	if (!filename)
		return (-1);

	if (text_content)
		size = _strlen(text_content);

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(file);
		return (1);
	}

	bytes_w = write(file, text_content, size);
	if (bytes_w == -1)
	{
		close(file);
		return (-1);
	}

	close(file);
	return (1);
}

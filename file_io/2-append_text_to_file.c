#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

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

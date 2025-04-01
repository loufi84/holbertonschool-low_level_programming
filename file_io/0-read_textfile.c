#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - A function that read a text file and prints it
 *				   to POSIX stdout
 *
 * @filename: The name of the file to be opened
 * @letters: The number of letters it could read and print
 *
 * Return: 0 if problem
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_r, bytes_w;
	int file = open(filename, O_RDONLY);
	char *buffer = malloc(letters);

	if (!filename)
	return (0);

	if (!buffer)
		return (0);

	if (file == -1)
	{
		free(buffer);
		return (0);
	}
	bytes_r = read(file, buffer, letters);
	if (bytes_r == -1)
	{
		close(file);
		free(buffer);
		return (0);
	}

	bytes_w = write(1, buffer, bytes_r);
	if (bytes_w == -1 || bytes_w < bytes_r)
	{
		close(file);
		free(buffer);
		return (0);
	}
	close(file);
	free(buffer);

	return (bytes_w);
}

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
	ssize_t bytes_r, bytes_w, tot_w = 0;
	int file;
	char *buffer;

	if (!filename || letters == 0)
		return (0);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(file);
		return (0);
	}
	bytes_r = read(file, buffer, letters);
	if (bytes_r == -1)
	{
		close(file);
		free(buffer);
		return (0);
	}

	while (tot_w < bytes_r)
	{
		bytes_w = write(1, buffer + tot_w, bytes_r - tot_w);
		if (bytes_w == -1)
		{
			close(file);
			free(buffer);
			return (0);
		}
		tot_w += bytes_w;
	}
	close(file);
	free(buffer);

	return (bytes_w);
}

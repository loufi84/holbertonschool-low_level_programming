#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * close_fd_exit - A function to handle closing exceptions
 *
 * @fd: The file descriptor causing troubles
 *
 * Return: Nothing
 */
void close_fd_exit(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error_exit - A function to handle errors printing and exit
 *
 * @code: Error code
 * @msg: Message to print (printf-like format)
 * @arg: Argument to pass for the message (integer or string)
 * @is_string: Flag to indicate if arg is a string (1) or integer (0)
 * @fd: File descriptor to close (can be -1 if none)
 *
 * Return: Nothing (exits the program)
 */
void error_exit(int code, const char *msg, void *arg, int fd)
{
	dprintf(STDERR_FILENO, msg, arg);
	if (fd != -1)
		close_fd_exit(fd);
	exit(code);
}

/**
 * copy_file - copies file content
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @src: source filename for error messages
 * @dest: destination filename for error messages
 * Return: 0 on success, -1 on failure
 */
int copy_file(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		return (-1);
	}

	return (0);
}

/**
 * main - copies the content of a file to another file
 *
 * @argc: Argument count
 * @argv: Values of arguments
 *
 * Return: 0 for success, various error codes if failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "", -1);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1], -1);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2], fd_from);

	if (copy_file(fd_from, fd_to) == -1)
	{
		error_exit(99, "Error: Can't write to %s\n", argv[2], fd_to);
	}

	close_fd_exit(fd_from);
	close_fd_exit(fd_to);

	return (0);
}

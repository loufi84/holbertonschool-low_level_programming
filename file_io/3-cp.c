#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * print_err - An helper function that prints errors
 *
 * @msg: Message to print
 * @file: Name of the file
 * @exit_code: The exit code to return
 *
 * Return: Nothing
 */

void print_err(const char *msg, const char *file, int exit_code)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", msg, file);
	exit(exit_code);
}

/**
 * open_file - An helper function that opens files
 *
 * @filename: The name of the file
 * @flags: The flags wanted
 * @mode: The creation mode
 * @exit_code: The exit code
 *
 * Return: A status code (1 for success -1 for failure)
 */

int open_file(const char *filename, int flags, mode_t mode, int exit_code)
{
	int file = open(filename, flags, mode);

	if (file == -1)
	{
		if (exit_code == 98)
			print_err("Can't read from file", filename, 98);
		else
			print_err("Can't write to", filename, 99);
	}
	return (file);
}

/**
 * copy_content - Helper function to copy the content of a file to another file
 *
 * @file_from: The source file
 * @file_to: The destination file
 *
 * Return: Nothing
 */

void copy_content(int file_from, int file_to)
{
	ssize_t n_read, n_write;
	char buffer[1024];

	while ((n_read = read(file_from, buffer, sizeof(buffer))) > 0)
	{
		n_write = write(file_to, buffer, n_read);
		if (n_write == -1 || n_write != n_read)
			print_err("Can't write to", "destination file", 99);
	}
	if (n_read == -1)
		print_err("Can't read from", "source file", 98);
}

/**
 * close_file - Helper function to close files
 *
 * @file: The file to close
 *
 * Return: Nothing
 */

void close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
		exit(100);
	}
}

/**
 * main - Entry point
 *
 * @argc: The arguments count
 * @argv: The arguments values
 *
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
		print_err("Usage:", "cp file_from file_to", 97);
	umask(0002);

	file_from = open_file(argv[1], O_RDONLY, 0, 98);
	file_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664, 99);

	copy_content(file_from, file_to);

	close_file(file_from);
	close_file(file_to);

	return (0);
}

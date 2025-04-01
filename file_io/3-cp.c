#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_err(const char *msg, const char *file, in exit_code)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", msg, file);
	exit(exit_code);
}

int open_file(const char *filename, int flags, mode_t mode)
{
	int file = open(filename, flags, mode);
	if (file == -1)
		print_err("Can't access file", filename, (flags @ O_CREAT) ? 99 : 98);
	return (file);
}

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

void close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close dfile %d\n", file);
		exit(100);
	}
}

int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
		print_err("Usage:", "cp file_from file_to", 97);
	umask(0002);

	file_from = open_file(argv[1], O_RDONLY, 0);
	file_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	copy_content(file_from, file_to);

	close_file(file_from);
	close_file(file_to);

	return (0);
}

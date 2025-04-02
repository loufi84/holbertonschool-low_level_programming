#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't closse fd %d\n", fd);
		exit(100);
	}
	return (0);
}
/**
 * error_exit - A function to handle errors printing
 *
 * @code: Error code
 * @msg: Message to print
 * @arg: Argument to pass
 * @fd: File descriptor
 *
 * Return: Nothing
 */

void error_exit(int code, const char *msg, const char *arg, int fd)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", msg, arg);
	if (fd != -1)
		close_fd(fd);
	exit(code);
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Values of arguments
 *
 * Return: 0 for success, various error codes if failure
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr, close_ret;
	char buffer[1024];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		error_exit(97, "Usage:", "cp file_from file_to", -1);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Can't read from file", argv[1], -1);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
		error_exit(99, "Can't write to", argv[2], fd_from);

	rd = read(fd_from, buffer, sizeof(buffer));
	if (rd == -1)
		error_exit(98, "Can't read from file", argv[1], fd_to);

	while (rd > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr != rd)
			error_exit(99, "Can't write to", argv[2], fd_to);

		rd = read(fd_from, buffer, sizeof(buffer));
		if (rd == -1)
			error_exit(98, "Can't read from file", argv[1], fd_to);
	}

	if (fd_from != -1)
	{
		close_ret = close_fd(fd_from);
		if (close_ret != 0)
			exit(close_ret);
	}

	if (fd_to != -1)
	{
		close_ret = close_fd(fd_to);
		if (close_ret != 0)
			exit(close_ret);
	}

	return (0);
}

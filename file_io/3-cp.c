#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints error message and exits with given code
 * @code: exit code
 * @msg: error message
 * @arg: additional argument for message (filename or fd)
 */
void error_exit(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written, close_status;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	close_status = close(fd_from);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	close_status = close(fd_to);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

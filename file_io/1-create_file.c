#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file with specific permissions
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	len = 0;
	while (text_content[len])
		len++;

	bytes_written = write(fd, text_content, len);

	close(fd);

	if (bytes_written == -1 || bytes_written != len)
		return (-1);

	return (1);
}

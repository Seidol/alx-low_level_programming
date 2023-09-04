#include "main.h"

/**
 * read_textfile - Reads a text file and prints its contents to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read.
 *
 * Return: On success, the actual number of bytes read and printed is returned.
 * On failure or if filename is NULL, 0 is returned.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, w, r;
	char buf[1024];

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	w = 0;
	while ((r = read(fd, buf, sizeof(buf))) > 0)
	{
		w += write(STDOUT_FILENO, buf, r);
		if (w == -1)
		{
			close(fd);
			return (0);
		}
	}

	close(fd);
	return (w);
}

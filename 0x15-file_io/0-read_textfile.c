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
	ssize_t fd, w;
	char c;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	w = 0;
	while (letters > 0 && read(fd, &c, 1) == 1)
	{
		if (write(STDOUT_FILENO, &c, 1) != 1)
		{
			close(fd);
			return (0);
		}
		w++;
		letters--;
	}

	close(fd);
	return (w);
}

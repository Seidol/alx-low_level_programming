#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(void);
void close_files(int source_fd, int destination_fd);

/**
 * allocate_buffer - Allocates a buffer for file content.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_files - Closes file descriptors.
 * @source_fd: The file descriptor for the source file.
 * @destination_fd: The file descriptor for the destination file.
 */
void close_files(int source_fd, int destination_fd)
{
	int close_result_source, close_result_destination;

	close_result_source = close(source_fd);
	close_result_destination = close(destination_fd);

	if (close_result_source == -1 || close_result_destination == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 97 on incorrect argument count, 98 on read error,
 *         99 on write error, and 100 on file descriptor error.
 *
 * Description: Copies the contents of a source file to a destination file.
 * If arguments are incorrect - exit code 97.
 * If source file cannot be read - exit code 98.
 * If destination file cannot be written - exit code 99.
 * If file descriptors cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_result, write_result;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer();
	source_fd = open(argv[1], O_RDONLY);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (source_fd == -1 || destination_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open files\n");
		free(buffer);
		close_files(source_fd, destination_fd);
		exit(98);
	}

	while ((read_result = read(source_fd, buffer, 1024)) > 0)
	{
		write_result = write(destination_fd, buffer, read_result);
		if (write_result == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			close_files(source_fd, destination_fd);
			exit(99);
		}
	}

	free(buffer);
	close_files(source_fd, destination_fd);

	return (0);
}

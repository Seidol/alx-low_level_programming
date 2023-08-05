#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The char to display
 *
 * Return: 1 when it is successful.
 * -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

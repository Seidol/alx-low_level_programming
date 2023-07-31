#include <unistd.h>

/**
 * _putchar - used to writes the character c to stdout
 * @c: The character to display
 *
 * Return: On success return 1.
 * On error, -1 is returned and error number is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

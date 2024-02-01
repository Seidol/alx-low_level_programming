#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes char c to stdout
 * @c: The char to print
 *
 * Return: success one.
 * On error, -1 is returned, and errnu is appropriately
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}

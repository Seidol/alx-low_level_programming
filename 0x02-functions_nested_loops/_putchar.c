#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes char c to stdout
 * @c: The char to print
 *
 * Return: succes 1.
 * On error, -1 is returned, and errnu is appropriately
 */
int _putchar(char)
{
	return(write(1, &c, 1));
}

#include "main.h"

/**
 * _puts - Prints a string to the standard output.
 *
 * @str: Pointer to the string to be printed.
 *
 * Return: void
 */

void _puts(char *str)
{
	int m;

	for (m = 0; str[m] != '\0'; m++)
	{
		_putchar(str[m]);
	}
	_putchar('\n');
}

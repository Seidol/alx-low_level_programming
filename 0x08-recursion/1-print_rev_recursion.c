#include "main.h"

/**
 * _print_rev_recursion - Displays a string in reverse.
 * @s: The string to be printed in reverse.
 *
 * Return: None (void function).
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}

	/* Add a newline at the end of the file */
	_putchar('\n');
}

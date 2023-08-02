#include "holberton.h"

/**
 * _print_rev_recursion - Displays a string in reverse
 * @s: string
 *
 * Return: one.
 * On error, -1 is returned.
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
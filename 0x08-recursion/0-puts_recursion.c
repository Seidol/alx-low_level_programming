#include "main.h"

/**
 * _puts_recursion - Displays a str fol by a ne line.
 * @s: str
 *
 * Return: 1 successful.
 * On error, -1 is returned.
 */
void _puts_recursion(char *s)
{
	if (*s == 0)
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1,'\n');
}
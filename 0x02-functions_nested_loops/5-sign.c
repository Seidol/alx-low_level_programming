#include "main.h"

/**
  * print_sign - Display sign of a num
  * @n: The num 2be checked
  *
  * Return: 1 for +num, -1 for -num or zero for anything.
  */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
}

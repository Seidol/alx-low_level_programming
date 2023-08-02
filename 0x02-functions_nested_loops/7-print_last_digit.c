#include "main.h"

/**
  * print_last_digit - Displays the last digit of number
  * @n: The n 2be treated
  *
  * Return: Val of the last digit of n.
  */
int print_last_digit(int n)
{
	int l;

	l = n % 10;

	if (l < 0)
	{
		l = l * -1;
	}

	_putchar(l + '0');

	return (l);
}

#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 *
 * @n: The integer for which the absolute value is calculated.
 *
 * Return: The absolute value of the integer.
 */

int _abs(int n)
{
	if (n > 0)
	{
		return (n);
	}
	else if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	else
	{
		return (n);
	}
}

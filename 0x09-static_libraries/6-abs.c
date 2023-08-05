#include "main.h"

/**
 * _abs - Computes the absolute value of an integer.
 *
 * @a: The integer for which the absolute value is calculated.
 *
 * Return: The absolute value of the integer.
 */

int _abs(int a)
{
	if (a > 0)
	{
		return (a);
	}
	else if (a < 0)
	{
		a = a * -1;
		return (a);
	}
	else
	{
		return (a);
	}
}

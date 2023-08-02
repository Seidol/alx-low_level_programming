#include "main.h"

/**
  * _abs - Cal the absolute val of an integer.
  * @c: The number to be computed.
  *
  * Return: Abs val of number or zero
  */
int _abs(int c)
{
	if (c < 0)
	{
		int absv;

		absv = c * -1;

		return (absv);
	}

	return (c);
}

#include "main.h"

/**
  * binary_to_uint - converts a binary string to an unsigned int
  * @b: the input binary string
  *
  * Return: the converted unsigned int, or 0 if invalid input
  */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dv = 0;
	int i = 0;

	if (!b)
		return (0);

	while (b[i] == '0' || b[i] == '1')
	{
		dv = (dv << 1) | (b[i] - '0');
		i++;
	}

	if (b[i] != '\0')
		return (0);

	return (dv);
}

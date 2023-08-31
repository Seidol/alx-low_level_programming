#include "main.h"

/**
  * get_bit - retrieves the value of a bit
  * at a specified index within a decimal number
  * @n: the decimal number to examine
  * @index: the index of the bit to retrieve
  *
  * Return: the value of the bit, or -1 if the index is invalid
  */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;
	int bv = (n & mask) ? 1 : 0;

	if (index > 63)
		return (-1);

	return (bv);
}

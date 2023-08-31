#include "main.h"

/**
  * set_bit - sets a specified bit at a given index to 1
  * @n: pointer to the number to modify
  * @index: index of the bit to set to 1
  *
  * Return: 1 if the operation is successful, -1 if index is out of range
  */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index > 63)
		return (-1);

	if ((*n & mask) == 0)
	{
		*n |= mask;
		return (1);
	}
	return (1);
}

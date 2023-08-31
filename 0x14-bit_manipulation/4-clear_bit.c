#include "main.h"

/**
  * clear_bit - resets the value of a specified bit to 0
  * @n: pointer to the number to modify
  * @index: index of the bit to reset
  *
  * Return: 1 if the operation is successful, -1 if index is out of range
  */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

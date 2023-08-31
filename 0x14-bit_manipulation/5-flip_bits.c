#include "main.h"

/**
  * flip_bits - counts the number of differing bits
  * required to transform one number into another
  * @n: the first number
  * @m: the second number
  *
  * Return: the count of differing bits
  */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result > 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}

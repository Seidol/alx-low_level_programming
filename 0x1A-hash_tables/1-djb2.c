#include "hash_tables.h"

/**
 * hash_djb2 - Calculates the hash value of a given string
 * using the DJB2 algorithm.
 * @str: The input string for which the hash value is calculated.
 *
 * Return: The computed hash number.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int h;
	int a;

	h = 5381;
	while ((a = *str++))
	{
		h = ((h << 5) + h) + a; /* hash * 33 + c */
	}
	return (h);
}

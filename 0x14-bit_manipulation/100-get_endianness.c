#include "main.h"

/**
 * get_endianness - determines if the machine uses little or big endian
 * Return: 0 for big endian, 1 for little endian
 */

int get_endianness(void)
{
	unsigned int a = 1;
	char *b = (char *) &a;

	return (*b);
}

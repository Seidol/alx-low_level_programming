#include "main.h"

/**
 * _memset - Fills the first n bytes
 * of the memory area pointed by s with a constant byte b.
 *
 * @s: Pointer to the memory area to be filled.
 * @b: The character to be copied.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n ; i++)
	{
		s[i] = b;
	}
	return (s);
}

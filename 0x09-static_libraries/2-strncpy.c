#include "main.h"

/**
 * _strncpy - Copies n bytes of the string pointed to by src,
 * including the null terminator, to the buffer pointed to by dest.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * @n: Number of bytes to copy from src.
 *
 * Return: Pointer to the destination buffer (dest).
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* If src is shorter than n, pad the remaining bytes with null terminators. */
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

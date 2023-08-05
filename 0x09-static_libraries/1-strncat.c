#include "main.h"

/**
 * _strncat - Concatenates n bytes from the string pointed to by src,
 * to the end of the string pointed to by dest.
 *
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Number of bytes to concatenate from src.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i;

	/* Get the length of the destination string */
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* Concatenate n bytes from src to dest */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	/* Null-terminate the resulting string */
	dest[dest_len + i] = '\0';

	return (dest);
}

#include "main.h"

/**
 * _strcpy - Copies the content of one string to another variable.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer (dest).
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0'; /* Null-terminate the destination string */

	return dest;
}

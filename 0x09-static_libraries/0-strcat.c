#include "main.h"

/**
 * _strcat - Concatenates the string pointed
 * to by src to the end of the string pointed to by dest.
 *
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0'; /* Ensure the destination string is null-terminated */

	return (ptr);
}

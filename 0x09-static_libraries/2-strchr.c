#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @s: Pointer to the string of characters to search in.
 * @c: The character to be located.
 *
 * Return: Pointer to the first occurrence of the character in the string.
 *         If the character is not found, returns NULL.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (*s == c) /* Check the null terminator too */
	{
		return (s);
	}

	return (NULL); /* Character not found in the string */
}

#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 *
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string containing characters to search for.
 *
 * Return: Pointer to the first occurrence of any character in accept in s,
 * or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int a, b;

	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; accept[b] != '\0'; b++)
		{
			if (accept[b] == s[a])
			{
				return (&s[a]);
			}
		}
	}
	return (NULL);
}

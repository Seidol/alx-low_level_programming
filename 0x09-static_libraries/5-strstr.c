#include "main.h"
#include <stdio.h>

/**
 * _strstr - Locates a substring inside a string.
 *
 * @haystack: The string to search.
 * @needle: The substring to search for.
 *
 * Return: Pointer to the location
 * of the substring inside the haystack, or NULL if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 1; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}

	return (NULL);
}

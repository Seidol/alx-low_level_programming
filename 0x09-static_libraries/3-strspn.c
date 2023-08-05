#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 *
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the substring with characters to match.
 *
 * Return: The number of characters in the initial segment of s that consist
 * entirely of characters from the accept string.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found = 0;

	while (*s != '\0')
	{
		found = 0;
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				count++;
				found = 1;
				break;
			}
			accept++;
		}
		if (found == 0)
			break;
		s++;
		accept = accept - count;
	}

	return (count);
}

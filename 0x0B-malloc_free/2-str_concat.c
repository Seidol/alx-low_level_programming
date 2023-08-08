#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: First input string
 * @s2: Second input string
 * Return: Pointer to newly allocated memory containing concatenated strings,
 * or NULL if memory allocation fails
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	int len_s1 = 0, len_s2 = 0, i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len_s1] != '\0')
		len_s1++;

	while (s2[len_s2] != '\0')
		len_s2++;

	concatenated = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

	if (concatenated == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		concatenated[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		concatenated[i] = s2[j];
		i++;
		j++;
	}
	concatenated[i] = '\0';

	return (concatenated);
}

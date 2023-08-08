#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - create an arr of size with each element initialized to char c
 * @size: unsigned int type
 * @c: char type
 * Return: Return pointer to the created array
 */

char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int b;

	if (size == 0)
	{
		return (NULL);
	}
	s = malloc((size) * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}
	b = 0;
	while (b < size)
	{
		s[b] = c;
		b++;
	}
	s[b] = '\0';
	return (s);
}

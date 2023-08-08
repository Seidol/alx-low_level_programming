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
	a = malloc((size) * sizeof(char));

	if (a == NULL)
	{
		return (NULL);
	}
	b = 0;
	while (b < size)
	{
		a[b] = c;
		b++;
	}
	a[b] = '\0';
	return (a);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - Duplicates a string in new memory space
 * @str: Input string
 * Return: Pointer to duplicated string NULL if allocation fails or str is NULL
 */
char *_strdup(char *str)
{
	char *duplicate;
	int length = 0, index = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
		return (NULL);

	while (str[index])
	{
		duplicate[index] = str[index];
		index++;
	}
	duplicate[index] = '\0';

	return (duplicate);
}

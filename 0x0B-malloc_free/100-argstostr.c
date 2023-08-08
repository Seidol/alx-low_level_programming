#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates command line arguments into a string
 * @ac: Number of command line arguments
 * @av: Array of command line arguments
 * Return: Pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i = 0, n, r = 0, total_length = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	while (i < ac)
	{
		n = 0;
		while (av[i][n])
		{
			total_length++;
			n++;
		}
		i++;
	}
	total_length += ac;

	str = malloc(sizeof(char) * (total_length + 1));
	if (str == NULL)
		return (NULL);

	i = 0;
	while (i < ac)
		n = 0;
		while (av[i][n])
			str[r] = av[i][n];
			r++;
			n++;
		switch (str[r])
		{
			case '\0':
				str[r++] = '\n';
				break;
		}
		i++;

	return (str);
}

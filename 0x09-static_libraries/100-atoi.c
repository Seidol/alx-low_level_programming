#include "main.h"
#include <limits.h>

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to the string to convert.
 *
 * Return: The integer that was converted.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	int i = 0;

	/* Handle signs */
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[0] == '+')
	{
		i++;
	}

	/* Convert string to integer */
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}

	return (sign * result);
}

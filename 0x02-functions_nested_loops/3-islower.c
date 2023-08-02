#include "main.h"

/**
  * _islower - This will Check if char is lower.
  * @c: char to be checked
  *
  * Return: one for lowercase char or zero for anything else
  */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}

	return (0);
}

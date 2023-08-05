#include <stdio.h>
#include "main.h"

/**
 * _putchar - write the char
 * @c: The char
 *
 * Return: 1 on success
 * -1 is returned and error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
  * print_binary - prints the binary representation
  * of an unsigned decimal number
  * @n: the decimal number to print in binary
  */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << 63;
	int print_flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			print_flag = 1;
		}
		else if (print_flag)
		{
			_putchar('0');
		}

		mask >>= 1;
	}

	if (!print_flag)
		_putchar('0');
}

#include "main.h"

/**
  * jack_bauer - Displays every min of day of Jack Bauer
  *
  * Return: no...
  */
void jack_bauer(void)
{
	int k, b, c, d;

	for (k = 0; k <= 2; k++)
	{
		for (b = 0; b <= 9; b++)
		{
			if ((k <= 1 && b <= 9) || (k <= 2 && b <= 3))
			{
				for (c = 0; c <= 5; c++)
				{
					for (d = 0; d <= 9; d++)
					{
						_putchar(k + '0');
						_putchar(b + '0');
						_putchar(58);
						_putchar(c + '0');
						_putchar(d + '0');
						_putchar('\n');
					}
				}
			}
		}
	}
}

#include "main.h"

/**
  * times_table - Displays the nine times table, starting with zero
  *
  * Return: empty.
  */
void times_table(void)
{
	int a, b, z, u, d;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			z = a * b;

			if (z > 9)
			{
				u = z % 10;
				d = (z - u) / 10;

				_putchar(44);
				_putchar(32);
				_putchar(d + '0');
				_putchar(u + '0');
			}
			else
			{
				if (b != 0)
				{
					_putchar(44);
					_putchar(32);
					_putchar(32);
				}

				_putchar(z + '0');
			}
		}

		_putchar('\n');
	}
}

#include <stdio.h>

/**
  * main - Displays three combo of nums
  *
  * Return: Always (Success)
  */
int main(void)
{
	int a, c, k, j;

	for (a = 48; a <= 57; a++)
	{
		for (c = 48; c <= 57; c++)
		{
			for (k = 48; k <= 57; k++)
			{
				for (j = 48; j <= 57; j++)
				{
					if (((k + j) > (a + c) &&  k >= a) || a < k)
					{
						putchar(a);
						putchar(c);
						putchar(' ');
						putchar(k);
						putchar(j);

					if (a + c + k + j == 227 && a == 57)
					{
					break;
					}
					else
					{
					putchar(',');
					putchar(' ');
					}
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}

#include <stdio.h>

/**
  * main - Displays three combo of nums
  *
  * Return: Always (Success)
  */
int main(void)
{
	int a, b, k;

	for (a = '0'; a <= '9'; a++)
	{
		for (b = '0'; b <= '9'; b++)
		{
			for (k = '0'; k <= '9'; k++)
			{
				if (a < b && b < k)
				{
					putchar(a);
					putchar(b);
					putchar(k);

					if (a != '7')
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}

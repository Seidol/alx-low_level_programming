#include <stdio.h>

/**
  * main - This C program will Displays a series of nums with commas
  *
  * Return: Always (Success)
  */
int main(void)
{
	int a;

	for (a = '0'; a <= '9'; a++)
	{
		putchar(a);

		if (a != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}

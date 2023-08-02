#include <stdio.h>

/**
  * main - This C program 'll displays num in reverse
  *
  * Return: Always
  */
int main(void)
{
	char a;

	for (a = 'z'; a >= 'a'; a--)
	{
		putchar(a);
	}

	putchar('\n');

	return (0);
}

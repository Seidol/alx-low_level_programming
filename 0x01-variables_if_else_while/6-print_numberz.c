#include <stdio.h>

/**
  * main - Displays the nums from 0 to 9
  *
  * Return: Always
  */
int main(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
		putchar(num);
	}

	putchar('\n');

	return (0);
}

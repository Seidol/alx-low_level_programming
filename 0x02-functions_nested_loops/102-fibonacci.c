#include <stdio.h>

/**
  * main - Displays first 52 fibo nums.
  *
  * Return: empty!
  */
int main(void)
{
	int i = 0;
	long j = 1, a = 2;

	while (i < 50)
	{
		if (i == 0)
			printf("%ld", j);
		else if (i == 1)
			printf(", %ld", a);
		else
		{
			a += j;
			j = a - j;
			printf(", %ld", a);
		}

		++i;
	}

	printf("\n");
	return (0);
}

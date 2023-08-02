/*
 * File: 104 task
 * Auth: Brennan D.
 */

#include <stdio.h>

/**
 * main - Displays first 98 Fibo num, starting with
 *        one and two, sepa by a comma fol by a space.
 *
 * Return: Alys 0.
 */
int main(void)
{
	int count;
	unsigned long f1 = 0, f2 = 1, sum;
	unsigned long fib1_half1, fib1_half2, fib2_half1, fib2_half2;
	unsigned long h1, h2;

	for (count = 0; count < 92; count++)
	{
		sum = f1 + f2;
		printf("%lu, ", sum);

		f1 = f2;
		f2 = sum;
	}

	fib1_half1 = f1 / 10000000000;
	fib2_half1 = f2 / 10000000000;
	fib1_half2 = f1 % 10000000000;
	fib2_half2 = f2 % 10000000000;

	for (count = 93; count < 99; count++)
	{
		h1 = fib1_half1 + fib2_half1;
		h2 = fib1_half2 + fib2_half2;
		if (fib1_half2 + fib2_half2 > 9999999999)
		{
			h1 += 1;
			h2 %= 10000000000;
		}

		printf("%lu%lu", h1, h2);
		if (count != 98)
			printf(", ");

		fib1_half1 = fib2_half1;
		fib1_half2 = fib2_half2;
		fib2_half1 = h1;
		fib2_half2 = h2;
	}
	printf("\n");
	return (0);
}

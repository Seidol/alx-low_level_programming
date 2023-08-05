#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * coinConverter - Helper function that calculates the minimum number of coins needed.
 * @amount: The input amount for which to find the minimum number of coins.
 *
 * Return: The number of coins needed minimum for the passed-in amount.
 */
int coinConverter(int amount)
{
	int count = 0;

	while (amount != 0)
	{
		if (amount % 10 == 9 || amount % 10 == 7)
			amount -= 2;
		else if (amount % 25 == 0)
			amount -= 25;
		else if (amount % 10 == 0)
			amount -= 10;
		else if (amount % 5 == 0)
			amount -= 5;
		else if (amount % 2 == 0)
		{
			if (amount % 10 == 6)
				amount -= 1;
			else
				amount -= 2;
		}
		else
			amount -= 1;

		count++;
	}

	return (count);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * Return: 0 if exactly 1 argument is passed into this program, 1 otherwise.
 */
int main(int argc, char *argv[])
{
	int amount, coin;

	coin = 0;

	if (argc != 2)
	{
		printf("Usage: %s <amount>\n", argv[0]);
		return (1);
	}

	amount = atoi(argv[1]);

	if (amount < 0)
		printf("0\n");
	else
	{
		coin = coinConverter(amount);
		printf("%d\n", coin);
	}

	return (0);
}

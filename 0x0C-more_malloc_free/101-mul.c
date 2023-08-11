#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * multiply - Multiply two integers
 * @num1: First integer
 * @num2: Second integer
 *
 * Return: Result of multiplication
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * is_positive_integer - Check if a string represents a positive integer
 * @num: The string to check
 *
 * Return: 1 if the string is a positive integer, 0 otherwise
 */
int is_positive_integer(const char *num)
{
	while (*num)
	{
		if (!isdigit(*num))
		{
			return (0);
		}
		num++;
	}
	return (1);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int num1;
	int num2;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = multiply(num1, num2);
	printf("%d\n", result);

	return (0);
}

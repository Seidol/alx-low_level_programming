#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints its own opcodes.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	int bytes, b;
	char *a;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	a = (char *)main;
	b = 0;

	while (b < bytes)
	{
		if (b == bytes - 1)
		{
			printf("%02hhx\n", a[b]);
			break;
		}

		printf("%02hhx ", a[b]);
		b++;
	}

	return (0);
}

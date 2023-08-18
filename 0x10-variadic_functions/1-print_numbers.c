#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints a list of numbers separated by a string.
 * @separator: The string to print between numbers (can be NULL).
 * @n: The count of numbers to print.
 * @...: The list of numbers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int index;

	va_start(numbers, n);

	index = 0;
	while (index < n)
	{
		printf("%d", va_arg(numbers, int));

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);

		index++;
	}

	printf("\n");

	va_end(numbers);
}

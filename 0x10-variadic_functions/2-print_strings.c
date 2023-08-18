#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints a list of strings separated by a string.
 * @separator: The string to print between strings (can be NULL).
 * @n: The count of strings to print.
 * @...: The list of strings to be printed.
 *
 * Description: If the separator is NULL, it is not printed.
 *              If one of the strings is NULL, "(nil)" is printed instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	char *str;
	unsigned int index;

	va_start(strings, n);

	index = 0;
	while (index < n)
	{
		str = va_arg(strings, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);

		index++;
	}

	printf("\n");

	va_end(strings);
}


#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints a variety of data types.
 * @format: List of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *st, *s = "";

	va_list list;
	va_start(list, format);

	if (format)
	{
		for (i = 0; format[i]; i++)
		{
			if (format[i] == 'c')
			{
				printf("%s%c", s, va_arg(list, int));
			}
			else if (format[i] == 'i')
			{
				printf("%s%d", s, va_arg(list, int));
			}
			else if (format[i] == 'f')
			{
				printf("%s%f", s, va_arg(list, double));
			}
			else if (format[i] == 's')
			{
				st = va_arg(list, char *);
				if (!st)
					st = "(nil)";
				printf("%s%s", s, st);
			}
			else
			{
				i++;
				continue;
			}

			s = ", ";
		}
	}

	printf("\n");
	va_end(list);
}


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
			switch (format[i])
			{
				case 'c':
					printf("%s%c", s, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", s, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", s, va_arg(list, double));
					break;
				case 's':
					st = va_arg(list, char *);
					if (!st)
						st = "(nil)";
					printf("%s%s", s, st);
					break;
				default:
					i++;
					continue;
			}

			s = ", ";
		}
	}

	printf("\n");
	va_end(list);
}

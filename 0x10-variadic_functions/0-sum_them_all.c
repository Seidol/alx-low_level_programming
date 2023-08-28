#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Computes the sum of a variable number of integers.
 * @n: Number of integers to sum up.
 * @...: Integers to be summed.
 *
 * Return: If n is 0, the function returns 0.
 *         Otherwise, it returns the sum of the provided integers.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);

	i = 0;
	while (i < n)
	{
		sum += va_arg(ap, int);
		i++;
	}

	va_end(ap);

	return (sum);
}

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void errors(void)
{
	printf("Error\n");
	exit(98);
}

void print_result(int *result, int len, int a)
{
	int i = 0;

	while (i < len - 1)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
		i++;
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
}

void perform_multiplication(char *s1, char *s2, int len1, int len2)
{
	int len = len1 + len2 + 1;
	int i, carry, digit1, digit2, *result, a = 0;
	char *temp_s1 = s1, *temp_s2 = s2;

	result = malloc(sizeof(int) * len);
	if (!result)
		exit(1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	len1 = len1 - 1;
	while (len1 >= 0)
	{
		digit1 = temp_s1[len1] - '0';
		carry = 0;
		int len2_temp = len2 - 1;
		while (len2_temp >= 0)
		{
			digit2 = temp_s2[len2_temp] - '0';
			carry += result[len1 + len2_temp + 1] + (digit1 * digit2);
			result[len1 + len2_temp + 1] = carry % 10;
			carry /= 10;
			len2_temp--;
		}
		if (carry > 0)
			result[len1 + len2_temp + 1] += carry;
		len1--;
	}
	print_result(result, len, a);
	free(result);
}

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	s1 = argv[1];
	s2 = argv[2];

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	perform_multiplication(s1, s2, len1, len2);
	return (0);
}

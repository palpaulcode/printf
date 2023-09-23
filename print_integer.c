#include "main.h"

/**
 * print_int - print integers for cases 'd' and 'i'
 * @vl: va_list argument
 *
 * Return: count of printed integers
 */
int print_int(va_list vl)
{
	int i = 0, n;

	n = va_arg(vl, int);

	i += print_integer(n);

	return (i);
}

/**
 * print_integer - prints integers (using recursion)
 * @n: integer to print
 *
 * Return: count of integer characters
 */
int print_integer(int n)
{
	int i = 0;

	if (n == INT_MIN)
	{
		i += _putchar('-');
		i += print_integer(INT_MAX / 10);
		i += _putchar(INT_MAX % 10 + 1 +  '0');
		return (i);

	}
	else if (n < 0)
	{
		i += _putchar('-');
		n = n * -1;
	}

	if (n / 10)
		i += print_integer(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

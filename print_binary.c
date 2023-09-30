#include "main.h"

/**
 * print_bin - get int from va_list, convert it
 * to binary and print the binary
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_bin(va_list vl)
{
	intmax_t n;
	uintmax_t un;
	int ret = 0;

	n = va_arg(vl, intmax_t);

	if (n < 0)
		un = -(uintmax_t)n;
	else
		un = (uintmax_t)n;

	ret += print_binary(un);

	return (ret);
}

/**
 * print_binary - convert int to binary and print
 * the binary
 * @n: the integer to print binary of
 *
 * Return: count of printed characters
 */
int print_binary(uintmax_t n)
{
	int len = 0, i, count = 0;
	uintmax_t tmp;

	tmp = n;
	/* calculate length of number when printed in binary */
	while (tmp > 0)
	{
		tmp >>= 1;
		len++;
	}

	/* print binary representation */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(((n >> i) & 1) ? '1' : '0');
	}

	count += len;

	return (count);
}


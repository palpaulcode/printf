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
	int n;
	int ret = 0;

	n = va_arg(vl, int);

	if (n < 0)
		return (-1);

	ret += print_binary(n);

	return (ret);
}

/**
 * print_binary - convert int to binary and print
 * the binary
 * @n: the integer to print binary of
 *
 * Return: count of printed characters
 */
int print_binary(int n)
{
	int x = 0, tmp;
	char buffer[CHAR_BIT * sizeof(n) + 1];
	char *ptr = &buffer[sizeof(buffer) - 1];

	*ptr = '\0'; /* terminating null byte */

	tmp = n;

	if (tmp > 0)
		tmp = -tmp;

	do {
		ptr--;
		*ptr = '0' - tmp % 2;
		tmp = tmp / 2;
	} while (tmp);

	if (n < 0)
	{
		ptr--;
		*ptr = '-';
	}

	x = print_string(ptr);

	return (x);
}


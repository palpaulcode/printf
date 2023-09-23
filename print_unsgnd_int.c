#include "main.h"

/**
 * print_unsgnd_int - prints unsigned int
 * @n: the unsigned int to print
 *
 * Return: no. of characters printed
 */
int print_unsgnd_int(unsigned int n)
{
	int i = 0;

	if (n == 0)
	{
		i += _putchar(0);
		return (i);
	}

	if (n / 10)
		i += print_unsgnd_int(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_unsgnd - print unsigned integers for case 'u'
 * @vl: va_list
 *
 * Return: no. of printed characters in the unsigned int
 */
int print_unsgnd(va_list vl)
{
	int i = 0;
	unsigned int n;

	n = va_arg(vl, unsigned int);

	i += print_unsgnd_int(n);

	return (i);
}


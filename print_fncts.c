#include "main.h"

/**
 * print_str - prints a string of characters for case 's'
 * @vl: va_list has the string to print
 *
 * Return: count of characters printed from string
 */
int print_str(va_list vl)
{
	int i = 0;
	char *str;

	str  = va_arg(vl, char *);

	if (str != NULL)
	{
		i += print_string(str);
	}
	else
	{
		str = "(null)";
		i += print_string(str);
	}

	return (i);
}

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

/**
 * print_octal - prints the octal number for case 'o'
 * @vl: va_list
 *
 * Return: no. of characters printed
 */
int print_octal(va_list vl)
{
	int i = 0;
	unsigned int ui;

	ui = va_arg(vl, unsigned int);

	i += print_octal_nums(ui);

	return (i);
}

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


#include "main.h"

/**
 * print_hex_X - prints hexadecimal for case 'X'
 * @vl: va_list contains unsigned int to print in hex
 *
 * Return: no. of characters printed int the hex
 */
int print_hex_X(va_list vl)
{
	int i = 0;
	unsigned int ui;

	ui = va_arg(vl, unsigned int);

	i += print_hexa_X(ui);

	return (i);
}


/**
 * print_hexa_X - prints hexadecimal in uppercase
 * @n: unsigned int to print in hex
 *
 * Return: no. of characters printed int the hex
 */
int print_hexa_X(unsigned int n)
{
	int i = 0;
	char hex[] = "0123456789ABCDEF";
	char mem[50];
	char *str;

	if (n == 0)
	{
		i += _putchar('0');
		return (i);
	}

	str = &mem[49];
	*str = '\0';

	while (n != 0)
	{
		*--str = hex[n % 16];
		n = n / 16;
	}
	i += print_string(str);

	return (i);
}



#include "main.h"

/**
 * print_hex_x - prints hexadecimal for case 'x'
 * @vl: va_list argument
 *
 * Return: no. characters printed in the hex
 */
int print_hex_x(va_list vl)
{
	int i = 0;
	unsigned int ui;

	ui = va_arg(vl, unsigned int);

	i += print_hexa_x(ui);

	return (i);
}

/**
 * print_hexa_x - prints hexadecimal in lowercase
 * @n: unsigned int to print in hex
 *
 * Return: no. characters printed in the hex
 */
int print_hexa_x(unsigned int n)
{
	int i = 0;
	char hex[] = "0123456789abcdef";
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


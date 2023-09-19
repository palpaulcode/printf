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

int print_addr(va_list vl)
{
	int i = 0;
	void *addr;

	addr = va_arg(vl, void *);

	i += print_address(addr);
}

/**
 * print_char - prints a character
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_char(va_list vl)
{
	int i;
	char ch;

	ch = va_arg(vl, int);
	i += _putchar(ch);

	return (i);
}

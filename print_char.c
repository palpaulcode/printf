#include "main.h"

/**
 * print_char - prints a character
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_char(va_list vl)
{
	int i = 0;
	char ch;

	ch = va_arg(vl, int);
	i += _putchar(ch);

	return (i);
}



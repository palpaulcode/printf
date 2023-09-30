#include "main.h"
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
 * print_octal_nums - converts unsigned int to octal
 * and prints the octal number
 * @n: integer to print in octal
 *
 * Return: no. of characters printed
 */
int print_octal_nums(unsigned int n)
{
	int c = 0; /* count of characters printed */
	int oct[100]; /* stores octal characters*/
	int i = 0, j;

	if (n == 0)
	{
		c += _putchar('0');
		return (c);
	}

	while (n != 0)
	{
		oct[i] = n % 8;
		n = n / 8;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		c += print_unsgnd_int(oct[j]);
	}

	return (c);
}


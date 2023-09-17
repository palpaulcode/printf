#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int print_ints(int);
int print_unsigned_ints(unsigned int);
int print_octal(unsigned int);
int print_hex_caps(unsigned int);
int print_hex_lower(unsigned int);
int print_str(char *);
int print_default(char *);

/**
 * _printf - prints characters according to some format
 * @format: printing format specifier
 *
 * Return: the length of the printed characters
 */
int _printf(const char *format, ...)
{
	va_list vl;
	unsigned int i = 0;
	int ret = 0;
	char ch;
	char *str;
	int prnt;
	unsigned int ui, ui2, ui3, ui4;
	char addr;

	if (format == NULL)
		return (-1);

	va_start(vl, format);

	while (format != NULL && *format != '\0')
	{
		if (*format != '%' && *format != '\0')
		{
			putchar(*format);
			ret++;
		}

		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					ch = va_arg(vl, int);
					ret += putchar(ch);
					break;
				case 's':
					str = va_arg(vl, char *);
					ret += print_str(str);
					break;
				case '%':
					putchar('%');
					ret++;
					break;
				case 'd':
				case 'i':
					prnt = va_arg(vl, int);
					ret += print_ints(prnt);
					break;
				case 'u':
					ui = va_arg(vl, unsigned int);
					ret += print_unsigned_ints(ui);
					break;
				case 'o':
					ui2 = va_arg(vl, unsigned int);
					ret += print_octal(ui2);
					break;
				case 'x':
					ui3 = va_arg(vl, unsigned int);
					ret += print_hex_lower(ui3);
					break;
				case 'X':
					ui4 = va_arg(vl, unsigned int);
					ret += print_hex_caps(ui4);
					break;
				case 'p':
					addr = va_arg(vl, int);
					ret += print_str(&addr);
					break;
				default:
					putchar('%');
					putchar(*format);
					ret += 2;
					break;
			}
		}
		format++;
	}
	return (ret);
}

/**
 * _putchar - prints a character
 *
 * Return: 1 for every character printed
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}

/**
 * print_ints - prints integers
 * @n: the integer to print
 *
 * Return: no. of printed integer
 */
int print_ints(int n)
{
	int i = 0;
	/* print -ve sign for negatives */
	if (n < 0)
	{
		i += _putchar('-');
		n = n * -1;
	}

	/* print zero */
	if (n == 0)
	{
		i += _putchar(0);
	}

	/**
	 * First, remove the last digit of number
	 * and print the remaining digits using
	 * recursion, then print the last digit
	 */
	if (n / 10)
		i += print_ints(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_unsigned_ints - prints unsigned ints
 * @n: the unsigned int to print
 *
 * Return: no. of characters printed
 */
int print_unsigned_ints(unsigned int n)
{
	int i = 0;
	/* print zero */
	if (n == 0)
	{
		i += _putchar(0);
	}

	/* Similar to function print_ints above */
	if (n / 10)
		i += print_ints(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_octal - prints octal
 * @n: integer to print in octal
 *
 * Return: no. of characters printed
 */
int print_octal(unsigned int n)
{
	int c = 0; /* count no. of printed chars */
	/* array - stores the octal number */
	int oct[1000];
	int i = 0, j; /* counter */

	while (n != 0)
	{
		oct[i] = n % 8;
		n = n / 8;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		c += print_unsigned_ints(oct[j]);
	}

	return (c);
}

/**
 * print_hex_caps - prints hexadecimal in uppercase
 * @n: the unsigned int to print in hexadecimal
 *
 * Return: no. of characters printed
 */
int print_hex_caps(unsigned int n)
{
	int i = 0; /* count no. of printed chars */
	char hex[] = "0123456789ABCDEF";
	char buf[50];
	char *str;

	str = &buf[49];
	*str = '\0';

	while (n != 0)
	{
		*--str = hex[n % 16];
		n = n / 16;
	}

	i += print_str(str);

	return (i);
}

/**
 * print_hex_lower - prints hexadecimal in lowercase
 * @n: the unsigned int int to print in hexadecimal
 *
 * Return: no. of characters printed
 */
int print_hex_lower(unsigned int n)
{
	int i = 0; /* count printed chars */
	char hex[] = "0123456789abcdef";
	char buf[50];
	char *str;

	str = &buf[49];
	*str = '\0';

	while (n != 0)
	{
		*--str = hex[n % 16];
		n = n / 16;
	}
	i += print_str(str);

	return (i);
}

/**
 * print_str - prints a string of characters
 * @str: the string to print
 *
 * Return: no. of printed characters
 */
int print_str(char *str)
{
	int i = 0; /* count printed chars */

	while (*str != '\0')
	{
		i += _putchar(*str++);
	}

	return (i);
}


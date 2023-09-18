#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _putchar(char);
int print_str(char *);
int print_int(int);

/**
 * _printf - prints characters
 * @format: format to use to print characters
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int prnt, ret = 0;
	char ch, *str;

	va_start(vl, format);

	while (format != NULL && *format != '\0')
	{
		if (*format != '%' && *format != '\0')
		{
			ret += _putchar(*format);
		}
		format++;

		if(*format == '%')
		{
			format++;

			switch(*format)
			{
				case 'c':
					ch = va_arg(vl, int);
					ret += _putchar(ch);
					break;
				case 's':
					str = va_arg(vl, char *);
					ret += print_str(str);
					break;
				case '%':
					ch = va_arg(vl, int);
					ret += _putchar(ch);
					break;
				case 'd':
				case 'i':
					prnt = va_arg(vl, int);
					ret += print_int(prnt);
					break;
			}
			format++;
		}
	}
	va_end(vl);
	return (ret);
}

/**
 * _putchar - print a character
 * @ch: the character to print
 *
 * Return: 1 for every character printed
 */
int _putchar(char ch)
{
	return(write(1, &ch, 1));
}

/**
 * print_str - prints a string of characters
 * @str: the string to print
 *
 * Return: count of characters printed from string
 */
int print_str(char *str)
{
	int i, ret = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		ret += _putchar(str[i]);
	}
	return (ret);
}

/**
 * print_int - prints integers (uses recursion)
 * @n: the integer to print
 *
 * Return: count of printed integers
 */
int print_int(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += _putchar('-');
		n = n * -1;
	}

	if (n / 10)
		i += print_int(n /10);

	i += _putchar(n % 10 + '0');

	return (i);
}

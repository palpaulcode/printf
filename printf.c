#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
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
	char ch, *str, *addr, ch2;
	unsigned int ui, ui2, ui3, ui4;

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
					ret += _putchar(*format);
					break;
				case 'd':
				case 'i':
					prnt = va_arg(vl, int);
					ret += print_int(prnt);
					break;
				case 'u':
					ui = va_arg(vl, unsigned int);
					ret += print_unsigned(ui);
					break;
				case 'o':
					ui2 = va_arg(vl, unsigned int);
					ret += print_octal(ui2);
					break;
				case 'x':
					ui3 = va_arg(vl, unsigned int);
					ret += print_hex_x(ui3);
					break;
				case 'X':
					ui4 = va_arg(vl, unsigned int);
					ret += print_hex_X(ui4);
					break;
				case 'p':
					addr = va_arg(vl, void *);
					/*ret += print_addr(addr);*/
					break;
				/*default:
					ret += print_unknown(format);
					break;*/
			}
			format++;
		}
	}
	va_end(vl);
	return (ret);
}

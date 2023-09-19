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
	int ret = 0;

	va_start(vl, format);
	int (*func)(va_list vl);

	while (format != NULL && *format != '\0')
	{
		if (*format != '%' && *format != '\0')
		{
			ret += _putchar(*format);
		}
		format++;

		if (*format == '%')
		{
			format++;

			ret += get_case(vl, format);

			format++;
		}
	}
	va_end(vl);
	return (ret);
}

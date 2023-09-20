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

	/* testing edge cases */
	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			ret += _putchar(*format);
			format++;
		}
		else
		/*if (*format == '%')*/
		{
			format++;
			ret += get_case(vl, format);
			format++;
		}
	}
	va_end(vl);
	return (ret);
}

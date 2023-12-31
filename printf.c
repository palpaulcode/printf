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
	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if ((!format[2] && format[0] == '%' && format[1] == ' '))
		return (-1);

	while (*format != '\0')
	{
		if (*format != '%')
			ret += _putchar(*format);

		if (*format == '%')
		{
			format++;
			if (valid_format(format) == 1) /* if not defined character */
				ret += print_unknown(format);
			else
				ret += get_case(vl, format);
		}
		format++;
	}
	va_end(vl);
	return (ret);
}

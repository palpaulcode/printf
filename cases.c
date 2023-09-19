#include "main.h"

/**
 * get_case - tests cases and prints appropriate characters
 * @vl: macro for va_list
 * @format: contains the cases to test
 *
 * Return: count of printed characters
 */
int get_case(va_list vl, const char *format)
{
	int ret = 0; /* ret keeps track of printed characters */

	switch (*format)
	{
		case 'c':
			ret += print_char(vl);
			break;
		case 's':
			ret += print_str(vl);
			break;
		case '%':
			ret += _putchar(*format);
			break;
		case 'd':
		case 'i':
			ret += print_int(vl);
			break;
		case 'u':
			ret += print_unsigned(vl);
			break;
		case 'o':
			ret += print_octal(vl);
			break;
		case 'x':
			ret += print_hex_x(vl);
			break;
		case 'X':
			ret += print_hex_X(vl);
			break;
		case 'p':
			/* called from helper file directly*/
			ret += print_address(vl);
			break;
		default:
			/* called directly from helper file*/
			ret += print_unknown(format);
			break;
	}
	return (ret);
}

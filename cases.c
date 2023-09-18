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
	int prnt, ret = 0; /* ret keeps track of printed characters */
	char ch, *str, *addr, ch2;
	unsigned int ui, ui2, ui3, ui4;

	switch (*format)
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
		default:
			ret += print_unknown(format);
			break;
	}
	return (ret);
}

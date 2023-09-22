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
	int i = 0;

	case_t cases[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_pct},
		{"d", print_int},
		{"i", print_int},
		/*{"b", },*/
		{"u", print_unsgnd},
		{"o", print_octal},
		{"x", print_hex_x},
		{"X", print_hex_X},
		{"p", print_addr},
		{NULL, NULL}
	};

	while (cases[i].ch)
	{
		if (*cases[i].ch == *format)
			ret += cases[i].f(vl);
		i++;
	}

	return (ret);
}

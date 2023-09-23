#include "main.h"

/**
 * print_rev - prints a reversed string.
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_rev(va_list vl)
{
	char *str, *str2;
	int len, count = 0;

	str = va_arg(vl, char *);

	if (str == NULL)
		return (-1);

	len = strlen(str);

	str2 = malloc(sizeof(char) *  len + 1);

	str2  = reverse(str);

	count += print_string(str2);

	return (count);
}

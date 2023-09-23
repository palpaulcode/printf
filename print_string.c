#include "main.h"

/**
 * print_str - prints a string of characters for case 's'
 * @vl: va_list has the string to print
 *
 * Return: count of characters printed from string
 */
int print_str(va_list vl)
{
	int i = 0;
	char *str;

	str  = va_arg(vl, char *);

	if (str != NULL)
	{
		i += print_string(str);
	}
	else
	{
		str = "(null)";
		i += print_string(str);
	}

	return (i);
}

/**
 * print_string - prints a string
 * @str: the string to print
 *
 * Return: count of printed characters
 */
int print_string(char *str)
{
	int i, ret = 0;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		ret += _putchar(str[i]);
	}
	return (ret);
}


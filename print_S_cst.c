#include "main.h"

/**
 * print_S - prints custom conversion specifier S
 * @vl: va_list argument
 *
 * Return: count of printed arguments
 */
int print_S(va_list vl)
{
	/*int len;
	char *str2;*/
	char *str;
	int count = 0;

	str = va_arg(vl, char *);

	if (str == NULL)
		return (-1);

	count += print_str_s(str);

	/*len = strlen(str);

	str2 = malloc(sizeof(char) * len + 1);

	str2 = custom_s_spec(str);

	count += print_string(str2);

	free(str2);*/

	return (count);
}

/**
 * custom_s_spec - prints non-printable characters this
 * way: \x, followed by the ASCII value in hex (uppercase)
 * @str: the string to work with
 *
 * Return: pointer to the new processed string
 */
/*char *custom_s_spec(char *str)
{
	int len, i;
	char *temp;

	ln = strlen(str);

	temp = malloc(sizeof(char) * len + 1);

	if (temp == NULL) // handle malloc return 
		return (NULL);

	// copy the string to this new memory
	for (i = 0; i < len; i++)
	{
		if ((str[i] < 32) || str[i] > 127)
		{
			temp[i] = "\x0";
			_putchar('0');
			// get hex and get frist 2characters 
			// add the two hex characters to temp 
		}
		else
		{
			temp[i] = str[i];
		}
	}

	return (temp);
}*/

int print_str_s(char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127) {
			putchar('\\');
			putchar('x');
			if (*str < 16)
				putchar('0'); /* Ensure 2 characters for hexadecimal*/
			print_hexa_X(*str);
			count += 4;
		}
		else
		{
			putchar(*str);
			count++;
		}
		str++;
	}

	return (count);
}

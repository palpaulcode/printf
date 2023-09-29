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

	free(str2);

	return (count);
}

/**
 * reverse - reverse a string
 * @str: the string to reverse
 *
 * Return: pointer to the reversed string
 */
char *reverse(char *str)
{
	int ln, hd, i;
	char *final, temp;

	ln = strlen(str);

	final = malloc(sizeof(char) * ln + 1);

	if (final == NULL) /* handle malloc return */
		return (NULL);

	for (i = 0; i < ln; i++)
		final[i] = str[i];
	final[i] = '\0';

	/* reverse the string here */
	for (hd = 0; hd < ln; hd++, ln--)
	{
		temp = final[ln - 1];
		final[ln - 1] = final[hd];
		final[hd] = temp;
	}

	return (final);
}


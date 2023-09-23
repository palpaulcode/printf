#include "main.h"

/**
 * print_bin - get int from va_list, convert it
 * to binary and print the binary
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_bin(va_list vl)
{
	int n;
	int ret = 0;

	n = va_arg(vl, int);

	if (n < 0)
		return (-1);

	ret += print_binary(n);

	return (ret);
}

/**
 * print_binary - convert int to binary and print
 * the binary
 * @n: the integer to print binary of
 *
 * Return: count of printed characters
 */
int print_binary(unsigned int n)
{
	int x = 0, i, l;
	char *str, *rts;

	if (n == 0)
		x += print_unsgnd_int(0);

	l = base_count(n, 2);
	str = malloc(sizeof(char) * l + 1);

	if (str == NULL) /* handle malloc return */
		return (-1);

	/* get base of number and store it as string */
	for (i = 0; n > 0; i++)
	{
		if (n % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		n /= 2;
	}

	str[i] = '\0'; /* add terminating null byte to the string */
	rts = reverse(str); /* get correct order of base */

	if (rts == NULL)
		return (-1);

	x += print_string(rts);

	free(rts);
	free(str);

	return (x);
	/* return (l); */
}


#include "main.h"

/**
 * print_hexa_x - prints hexadecimal in lowercase
 * @n: unsigned int to print in hex
 *
 * Return: no. characters printed in the hex
 */
int print_hexa_x(unsigned int n)
{
	int i = 0;
	char hex[] = "0123456789abcdef";
	char mem[50];
	char *str;

	if (n == 0)
	{
		i += _putchar('0');
		return (i);
	}
	str = &mem[49];
	*str = '\0';

	while (n != 0)
	{
		*--str = hex[n % 16];
		n = n / 16;
	}
	i += print_string(str);

	return (i);
}

/**
 * print_hexa_X - prints hexadecimal in uppercase
 * @n: unsigned int to print in hex
 *
 * Return: no. of characters printed int the hex
 */
int print_hexa_X(unsigned int n)
{
	int i = 0;
	char hex[] = "0123456789ABCDEF";
	char mem[50];
	char *str;

	if (n == 0)
	{
		i += _putchar('0');
		return (i);
	}

	str = &mem[49];
	*str = '\0';

	while (n != 0)
	{
		*--str = hex[n % 16];
		n = n / 16;
	}
	i += print_string(str);

	return (i);
}

/**
 * print_address - print address of a variable case 'p'
 * @addr: variable to print address of
 *
 * Return: no. of characters in the address
 */
int print_address(void *addr)
{
	int count = 0; /* counts characters printed */
	int rs = 0, i, dg;
	unsigned long n = (unsigned long) addr;
	unsigned long tmp = n;
	char hex[16];
	char hex_d[16] = "0123456789abcdef";

	while (tmp != 0)
	{
		rs++;
		tmp = tmp / 16;
	}
	count += _putchar('0');
	count += _putchar('x');
	if (n == 0)
	{
		count += _putchar('0');
	}
	if (n != 0)
	{
		for (i = rs - 1; i >= 0; i--)
		{
			dg = n % 16;
			hex[i] = hex_d[dg];
			n = n / 16;
		}
		for (i = 0; i < rs; i++)
			count += _putchar(hex[i]);
	}

	return (count);
}


/**
 * print_unknown - case 'default'
 * prints undefined character preceded by
 * '%' (xter not covered in cases)
 * @unknown: pointer to the undefined character
 *
 * Return: count of printed characters
 */
int print_unknown(const char *unknown)
{
	int i = 0;

	i += _putchar(*--unknown);
	i += _putchar(*++unknown);

	return (i);
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


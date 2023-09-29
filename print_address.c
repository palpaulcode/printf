#include "main.h"

/**
 * print_addr - prints an address
 * @vl: va_list argument
 *
 * Return: count of printed characters
 */
int print_addr(va_list vl)
{
	int i = 0;
	void *addr;

	addr = va_arg(vl, void *);

	i += print_address(addr);

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
	char *str = "(nil)";

	if (addr == NULL)
	{
		count += print_string(str);
		return (count);
	}


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



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
	int i = 0; /* counts characters printed */
	char *str = (void *)&addr;

	i += print_string(str);

	return (i);
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

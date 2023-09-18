#include "main.h"

/**
 * print_hex_x - prints hexadecimal in lowercase
 * @n: unsigned int to print in hex
 *
 * Return: no. characters printed in the hex
 */
int print_hex_x(unsigned int n)
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
	i += print_str(str);

	return (i);
}

/**
 * print_hex_X - prints hexadecimal in uppercase
 * @n: unsigned int to print in hex
 *
 * Return: no. of characters printed int the hex
 */
int print_hex_X(unsigned int n)
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
	i += print_str(str);

	return (i);
}

/**
 * print_addr - print address of a given string
 * @str: string to print address of
 *
 * Return: no. of characters in the address
 */
int print_addr(void *str)
{
	int i = 0; // counts characters printed
	void *addr = &str;

	i += print_str(addr);

	return (i);
}


/**
 * print_unknown - prints an undefined character
 * preceded by '%' (xter not covered in cases)
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

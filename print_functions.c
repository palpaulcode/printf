#include "main.h"
#include <unistd.h>

/**
 * _putchar - print a character
 * @ch: the character to print
 *
 * Return: 1 for every character printed
 */
int _putchar(char ch)
{
	return(write(1, &ch, 1));
}

/**
 * print_str - prints a string of characters
 * @str: the string to print
 *
 * Return: count of characters printed from string
 */
int print_str(char *str)
{
	int i, ret = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		ret += _putchar(str[i]);
	}
	return (ret);
}

/**
 * print_int - prints integers (uses recursion)
 * @n: the integer to print
 *
 * Return: count of printed integers
 */
int print_int(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += _putchar('-');
		n = n * -1;
	}

	if (n / 10)
		i += print_int(n /10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_unsigned - prints unsigned integers
 * @n: the unsigned integer to print
 *
 * Return: no. of printed characters in the unsigned int
 */
int print_unsigned(unsigned int n)
{
	int i = 0;

	if (n == 0)
		i += _putchar(0);

	if (n / 10)
		i += print_unsigned(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_octal - converts unsigned int to octal
 * and prints the octal number
 * @n: integer to print in octal
 *
 * Return: no. of characters printed
 */
int print_octal(unsigned int n)
{
	int c = 0; /* count of characters printed */
	int oct[100]; /* stores octal characters*/
	int i = 0, j;

	while (n != 0)
	{
		oct[i] = n % 8;
		n = n / 8;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		c += print_unsigned(oct[j]);
	}

	return (c);
}

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
/*
int print_addr(char *str)
{
	int i = 0; // counts characters printed
	char addr = &str;

	while (addr[i] != '\0')
	{
		_putchar(addr[i]);
		i++;
	}

	return (i);
}
*/

int print_unknown(const char *unknown)
{
	int i = 0;

	i += _putchar(*--unknown);
	i += _putchar(*++unknown);
	
	return (i);
}

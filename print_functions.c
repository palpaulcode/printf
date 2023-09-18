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

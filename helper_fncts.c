#include "main.h"

/**
 * print_string - prints a string
 * @str: the string to print
 *
 * Return: count of printed characters
 */
int print_string(char *str)
{
	int i, ret = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		ret += _putchar(str[i]);
	}
	return (ret);
}
/**
 * print_integer - prints integers (using recursion)
 * @n: integer to print
 *
 * Return: count of integer characters
 */
int print_integer(int n)
{
	int i = 0;

	if (n < 0)
	{
		i += _putchar('-');
		n = n * -1;
	}

	if (n / 10)
		i += print_integer(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_unsigned_int - prints unsigned int
 * @n: the unsigned int to print
 *
 * Return: no. of characters printed
 */
int print_unsigned_int(unsigned int n)
{
	int i;

	if (n == 0)
		i += _putchar(0);

	if (n / 10)
		i += print_unsigned_int(n / 10);

	i += _putchar(n % 10 + '0');

	return (i);
}

/**
 * print_octal_nums - converts unsigned int to octal
 * and prints the octal number
 * @n: integer to print in octal
 *
 * Return: no. of characters printed
 */
int print_octal_nums(unsigned int n)
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
		c += print_unsigned_int(oct[j]);
	}

	return (c);
}

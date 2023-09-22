#include "main.h"

/**
 * _putchar - print a character
 * @ch: the character to print
 *
 * Return: 1 for every character printed
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}


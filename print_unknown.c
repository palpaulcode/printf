#include "main.h"

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


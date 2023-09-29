#include "main.h"

/**
 * base_count - get no of characters for a given base
 * @n: The number to calculate base of
 * @b: base to use
 *
 * Return: Number of characters for a number in
 * the given base
 */
int base_count(unsigned int n, int b)
{
	unsigned int i;

	for (i = 0; n > 0; i++)
		n = n / b;

	return (i);
}


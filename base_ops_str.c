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

/**
 * reverse - reverse a string
 * @str: the string to reverse
 *
 * Return: pointer to the reversed string
 */
char *reverse(char *str)
{
	int ln, hd, i;
	char *final, temp;

	ln = strlen(str);

	final = malloc(sizeof(char) * ln + 1);

	if (final == NULL) /* handle malloc return */
		return (NULL);

	for (i = 0; i < ln; i++)
		final[i] = str[i];
	final[i] = '\0';

	/* reverse the string here */
	for (hd = 0; hd < ln; hd++, ln--)
	{
		temp = final[ln - 1];
		final[ln - 1] = final[hd];
		final[hd] = temp;
	}

	return (final);
}

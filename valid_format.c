#include "main.h"

/**
 * valid_format - checks if a character following a '%'
 * is defined
 * @ch: the character to check
 *
 * Return: 0 if its a defined character, 1 if its not
 */
int valid_format(const char *ch)
{
	int i = 0;
	/* Add after X, S, R */
	char defined[] = {'c', 's', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'p', 'r'};

	while (defined[i])
	{
		if (defined[i] == *ch)
			return (0);
		i++;
	}
	return (1);
}

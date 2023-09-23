#include "main.h"

/**
 * encode_rot13 - encodes a string using rot 13
 * @vl: va_list argument
 *
 * Return: count of printed characters from rotated string
 */
int encode_rot13(va_list vl)
{
	char *str, *str2;
	int count = 0, len;

	str = va_arg(vl, char *);

	if (str == NULL)
		return (-1);

	len = strlen(str);

	str2 = malloc(sizeof(char) * len + 1);

	str2 = rot13(str);

	count += print_string(str2);

	free(str2);

	return (count);
}

/**
 * rot13 - encode a string using rot13
 * @s: the string to encode
 *
 * Return: the encoded string
 */
char *rot13(char *s)
{
	int i, j, len;
	char *str;

	char st[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rt[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	len = strlen(s);

	str = malloc(sizeof(char) * len + 1);

	if (str == NULL) /* handle malloc return */
		return (NULL);

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (st[j] != '\0')
		{
			if (s[i] == st[j])
			{
				str[i] = rt[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (str);
}

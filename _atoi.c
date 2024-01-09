#include "shell.h"

/**
 * interactive - evaluates to true if shell is in interactive mode
 * @info: structure address
 *
 * Return: returns 1 if it's in interactive mode or 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - inspects if char is a delimeter
 * @c: Actual char to examine
 * @delim: the string delimeter
 * Return: returns 1 if true or 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - looks for alphabetic characters
 *@c: char input
 *Return: returns 1 if c is alphabet, or 0 if it's not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: impending converted string
 *Return: returns 0 if there's no number in string,
 *or converted number otherwise
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0;  s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

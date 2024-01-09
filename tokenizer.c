#include "shell.h"

/**
 * **strtow - splits a strings and repeated delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, v, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, v = 0; v < numwords; v++)
	{
		while (is_delim(str[x], d))
			x++;
		k = 0;
		while (!is_delim(str[x + k], d) && str[x + k])
			k++;
		s[v] = malloc((k + 1) * sizeof(char));
		if (!s[v])
		{
			for (k = 0; k < v; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[v][m] = str[x++];
		s[v][m] = 0;
	}
	s[v] = NULL;
	return (s);
}

/**
 * **strtow2 - string splittert
 * @str: string input
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int x, v, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, v = 0; v < numwords; v++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		k = 0;
		while (str[x + k] != d && str[x + k] && str[x + k] != d)
			k++;
		s[v] = malloc((k + 1) * sizeof(char));
		if (!s[v])
		{
			for (k = 0; k < v; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[v][m] = str[x++];
		s[v][m] = 0;
	}
	s[v] = NULL;
	return (s);
}


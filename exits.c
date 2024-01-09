#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the location to receive the copied string
 *@src: source string
 *@n: the number of characters to be copied
 *Return: the correlation string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, v;
	char *s = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		v = x;
		while (v < n)
		{
			dest[v] = '\0';
			v++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates 2 strings
 *@dest: first string
 *@src: second string
 *@n: number of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x, v;
	char *s = dest;

	x = 0;
	v = 0;
	while (dest[x] != '\0')
		x++;
	while (src[v] != '\0' && v < n)
	{
		dest[x] = src[v];
		x++;
		v++;
	}
	if (v < n)
		dest[x] = '\0';
	return (s);
}

/**
 **_strchr - identifies a character in a string
 *@s: string to be parsed
 *@c: the char to look for
 *Return: (s) a pointer to the memory address s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


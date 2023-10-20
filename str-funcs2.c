#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: destination string to be copied to
 *@src: source string
 *@n: amount of characters to be copied
 *
 *Return: concatenated of string
*/

char *_strncpy(char *dest, char *src, int n)
{
	int l, m;
	char *d = dest;

	l = 0;
	while (src[l] != '\0' && l < n - 1)
	{
		dest[l] = src[l];
		l++;
	}
	if (l < n)
	{
		m = l;

		while (m < n)
		{
			dest[m] = '\0';
			m++;
		}
	}

	return (d);
}

/**
 **_strncat - concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *
 *Return: concatenated strin
 *
*/

char *_strncat(char *dest, char *src, int n)
{
	int l, m;
	char *d = dest;

	l = 0;
	m = 0;
	while (dest[l] != '\0')
		l++;
	while (src[m] != '\0' && m < n)
	{
		dest[l] = src[m];
		l++;
		m++;
	}
	if (m < n)
		dest[l] = '\0';

	return (d);
}

/**
 **_strchr - locates a character in a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: s a pointer to the memory area s
 *
*/

char *_strchr(char *s, char c)
{
		do {
		if (*s == c)

		return (s);

	} while (*s++ != '\0');

	return (NULL);
}


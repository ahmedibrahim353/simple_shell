#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: string whose length to check
 * Return: Integer leng of string
 *
*/

int _strlen(char *s)
{
	int l = 0;

	if (!s)
		return (0);

	while (*s++)
		l++;

	return (l);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: first strang
 * @s2: Second strang
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 *
*/


int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search.
 * @needle: substring to find.
 * Return: Addresses of next char of haystack or null
 *
*/

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)

			return (NULL);

	return ((char *)haystack);
}


/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: Pointer to destination Buffer
 *
*/

char *_strcat(char *dest, char *src)
{
	char *Te = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (Te);
}


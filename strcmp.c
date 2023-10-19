#include "main.h"

/**
 *_strcmp -function that copies a string.
 *@s1: Pointer to first string to compare
 *@s2: Pointer to second string to compare
 *Return: integer comparison
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

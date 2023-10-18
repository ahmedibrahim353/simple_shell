#include "main.h"

/**
 *_strncmp -function that compares a string.
 *@s1: Pointer to first string to compare
 *@s2: Pointer to second string to compare
 *@len: Length of string to compare
 *Return: integer comparison
 */

int _strncmp(char *s1, char *s2, int len)
{
	int counter = 0;

	while ((*s1 != '\0' && *s1 == *s2) || (counter < len))
	{
		s1++;
		s2++;
		counter++;
	}

	return (*s1 - *s2);
}

#include "main.h"

/**
 *_strcpy -  Function to copy one string to another string.
 *@source: source string
 *@destination: destination string
 *Return: length of string.
 */

void _strcpy(char *destination, char *source)
{
	if (source == NULL)
		exit(EXIT_FAILURE);
	else
	{
		int i = 0;

		while (source[i] != '\0')
		{
			destination[i] = source[i];
			i++;
		}
		destination[i] = '\0';
	}
}

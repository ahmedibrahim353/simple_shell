#include "main.h"

/**
 *_strcpy -  Function to copy one string to another string.
 *@source: source string
 *@destination: destination string
 *Return: length of string.
 */

char * _strdup(char *source)
{
	if (source == NULL)
		exit(EXIT_FAILURE);
	else
	{
		int i = 0;
		char *des = NULL;

		des = malloc( (_strlen(source)) * sizeof(char));
		if (des == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		while (source[i] != '\0')
		{
			des[i] = source[i];
			i++;
		}
		des[i] = '\0';
	return des;
	}
}

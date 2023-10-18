#include "main.h"

/**
 *_path - function that prints each directory contained in the the environment
 *variable PATH, one directory per line.
 *@name: the name of the environment variable
 *@delim: the delimiter
 *Return: One directory per line.
 */

void _path(char *name, char *delim)
{
	char *token = strtok(name, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
}

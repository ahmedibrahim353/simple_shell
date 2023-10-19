#include "main.h"

/**
 *_getenv - function that compares the given name to the
 *environment variable and return the value
 *@name: the name of the environment variable
 *Return: THE value of the environment variable
 */

char *_getenv(char *name)
{
	char **env = environ;
	size_t namelen = _strlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, namelen) == 0 && (*env)[namelen] == '=')
		{
			return (&(*env)[namelen + 1]);
		}
		env++;
	}

	return (NULL);
}

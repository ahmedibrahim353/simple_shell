#include "main.h"

/**
 *_environ -  pointer to an array of strings.
 *Each string in this array represents an environment variable
 *in the form "name=value".
 *Return: environment variable name
 */

int _environ(void)
{
	char **env = environ;
	int fd = 1, len;

	while (*env != NULL)
	{
		len = _strlen(*env);

		write(fd, *env, len);
		write(fd, "\n", 1);

		env++;
	}

	return (0);
}

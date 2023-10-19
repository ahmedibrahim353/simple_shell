#include "main.h"

/**
 *_exec - function to execute.
 *@array_Of_Words: the array of argv
 *@argv: the array of arguments
 *Return: 0 on success
 */

int _exec(char **array_Of_Words, char **argv)
{
	char *full_Command = NULL;
	printf("command: %s\n", array_Of_Words[0]);
	full_Command = _get_path(array_Of_Words[0]);
		printf("f_command: %s\n", full_Command);

	if (execve(full_Command, array_Of_Words, NULL) == -1)
	{
		switch (errno)
		{
			case ENOENT:
				 write(1, argv[0], 5);
				break;
			case EFAULT:
				break;
			case EACCES:
				break;
			default:
				break;
		}

		exit(EXIT_FAILURE);
	}

	return (0);
}

#include "main.h"

/**
 * _fork - function to fork a process
 * @array_Of_Words: the array of argv
 * @argv: the array of arguments
 * Return: 0 on success
 */

int _fork(char **array_Of_Words, char **argv)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
	}

	if (child_pid == 0)
	{
		_exec(array_Of_Words, argv);
	}
	else
	{
		_wait(status);
	}

	return (0);
}

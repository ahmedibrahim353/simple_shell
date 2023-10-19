#include "main.h"

/**
 *_execute_command - function to execute.
 *@array_Of_Words: the array of argv
 *@argv: the array of arguments
 *Return: void
 */

void _execute_command(char **array_Of_Words, char **argv)
{
	char arr[][15] = {"exit", "env", "com_exe"};
	char *full_Command = NULL;

	full_Command = _get_path(array_Of_Words[0]);
	if ((_strcmp(array_Of_Words[0], arr[0])) == 0)
	{
		exit_program(array_Of_Words[0]);
	}
	else if ((_strcmp(array_Of_Words[0], arr[1])) == 0)
	{
		_environ();
	}
	else if (full_Command != NULL)
	{
		_fork(full_Command, array_Of_Words, argv);
	}
	else
	{
		_puts(argv[0]);
		_puts(": 1: ");
		_puts(array_Of_Words[0]);
		_puts(": command not found\n");
	}
}

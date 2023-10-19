#include "main.h"

/**
 *main - Write a program that prints all the arguments, without using ac.
 *@argv: is a NULL terminated array of strings
 *@argc: is the number of items in av
 *Return: Always 0.
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char **array_Of_Words = NULL, *line = NULL, *delim = " \n\t";
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
	{
		_puts("$ ");
		while ((nread = getline(&line, &len, stdin)) != -1)
		{
			if (nread != 1)
			{
				array_Of_Words = _stringTok(line, delim);
				_execute_command(array_Of_Words, argv);
			}
			_puts("$ ");
		}
	}
	else
	{
		while (getline(&line, &len, stdin) != -1)
		{
			array_Of_Words = _stringTok(line, delim);
			_execute_command(array_Of_Words, argv);
		}
	}
	free(line);
	free(array_Of_Words);
	return (0);
}

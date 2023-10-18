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
	int file_status;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		while ((nread = getline(&line, &len, stdin)) != -1)
		{
			if (nread != 1)
			{
				array_Of_Words = _stringTok(line, delim);
				exit_program(array_Of_Words[0]);
				if (isEnv(array_Of_Words[0]))
				{
					printf("$ ");
					continue; }
				_path(getenv("PATH"), ":");
				file_status = _stat(array_Of_Words[0]);
				file_status == 0 ? _fork(array_Of_Words, argv) :
				printf("%s:command not found\n", argv[0]);	}
			printf("$ ");	}	}
	else
	{
		while (getline(&line, &len, stdin) != -1)
		{
			array_Of_Words = _stringTok(line, delim);
			exit_program(array_Of_Words[0]);
			if (isEnv(array_Of_Words[0]))
			{
				printf("$ ");
				continue;	}
			file_status = _stat(array_Of_Words[0]);

			file_status == 0 ? _fork(array_Of_Words, argv) :
			printf("%s:command not found\n", argv[0]);	}	}
	free(line);
	free(array_Of_Words);
	exit(EXIT_SUCCESS);
}

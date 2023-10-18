#include "main.h"

/**
 *isEnv - function to get environment variable
 *@input: user input string
 *Return: nothing
 */

int isEnv(char *input)
{
	if (_strcmp(input, "env") == 0)
	{
		_environ();
		return (1);
	}
	else
	{
		return (0);
	}
}

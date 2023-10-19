#include "main.h"

/**
 *exit_program - function to exit the program
 *@input: user input string
 *Return: nothing
 */

void exit_program(char *input)
{
	if (_strcmp(input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

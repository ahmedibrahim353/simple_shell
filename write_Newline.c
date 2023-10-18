#include "main.h"

/**
 *_write_newLine - function to handel printing line
 *@string: string
 *Return: 0 on success
 */

int _write_newLine(char *string)
{

	if (string == NULL)
	{
		return (-1);
	}
	else
	{
		_write(string);
		write(1, "\n", 1);
		return (0);
	}
}

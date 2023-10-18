#include "main.h"

/**
 *_write - function to handel printing line
 *@string: string
 *Return: 0 on success
 */

int _write(char *string)
{

	if (string == NULL)
	{
		return (-1);
	}
	else
	{
		int len;

		len = _strlen(string);
		write(1, string, len);
		return (0);
	}
}

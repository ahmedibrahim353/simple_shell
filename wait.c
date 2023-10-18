#include "main.h"

/**
 *_wait - function to suspends execution of the calling process
 *until one of its children terminates..
 *@status: integer
 *Return: 0 on success
 */

int _wait(int status)
{

	if (wait(&status) == -1)
	{
		perror("wait");
		return (EXIT_FAILURE);
	}


	return (0);
}

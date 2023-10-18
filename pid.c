#include "main.h"

/**
 *_pid - function to return chid pid
 *Return: child pid
 */

int _pid(void)
{
	pid_t child_pid;

	child_pid = getpid();

	return (child_pid);
}

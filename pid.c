i#include "main.h"

/**
 *_pid - function to return chid pid
 *Return: child pid
 */

int _pid(void)
{
	pid_t child_pid;

	child_pid = getpid();

	printf("_PID: child PID  : %d\n", child_pid);

	return (child_pid);
}

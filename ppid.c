#include "main.h"

/**
 *_ppid - function to return parent pid
 *Return: parent pid
 */

int _ppid(void)
{
	pid_t parent_pid;

	parent_pid = getppid();

	printf("_PPID: parent PID  : %d\n", parent_pid);

	return (parent_pid);
}

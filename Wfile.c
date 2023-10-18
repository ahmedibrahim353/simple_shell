#include "main.h"

/**
 *_whichFile - system call that gets the status of a file.
 *@filename: the path ||[] to the file or directory
 *Return: 0 on success, -1 on error.
 */

int _whichFile(char *filename[])
{
	struct stat st;
	unsigned int i;

	i = 1;

	while (filename[i])
	{
		if (stat(filename[i], &st) == 0)
		{
			printf(" _which: FOUND\n");
		}
		else
		{
			printf("_which:  NOT FOUND\n");
		}

		i++;
	}

	return (0);
}

#include "shell.h"

void handl_pwd()
{
	char cwd[BUFSIZE];

	if (getcwd(cwd, sizeof(cwd)))
	{
		printf("%s\n", cwd);
	}
}

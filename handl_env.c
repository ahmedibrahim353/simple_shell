#include "shell.h"              
#include "comm_sepa.h"

void handl_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);	
}

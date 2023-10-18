#include "shell.h"
#include "comm_sepa.h"

void handl_exit(char *line, int line_number, list_cmd *sep_cmds)
{
	char *token;
	int number;

	token = strtok(line, " ");
	token = strtok(NULL, " ");

	if (!token)
	{
		free_list(sep_cmds);
		free(line);
		exit(DATA.exit_code);
	}
	if (_strcmp(token, "0") == 0)
	{
		free_list(sep_cmds);
		free(line);
		exit(0);
	}
	number = atoi(token);
	if (number == 0 || number < 0)
	{
		if (!isatty(0))
		{
			fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n",
					 line_number, token);
			free_list(sep_cmds);
			free(line);
			exit(2);
		}
		else
		{
			fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n",
					 line_number, token);
			DATA.exit_code = 2;
			return;
		}
	}
	else
	{
		free(line);
		free_list(sep_cmds);
		exit(number);
	}
}

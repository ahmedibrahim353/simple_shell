#include "shell.h"
#include "comm_sepa.h"

global DATA = {0};
int main(int ar, char **av, char **env)
{
	(void)ar;
	signal(SIGINT, handl_signal);
	mainloop(av, env);
	return (0);
}
void mainloop(char **av, char**env)
{
	char *line = NULL;
	size_t buff_size = 0;
	int line_number = 0;
	list_cmd *sep_cmds;
	(void) av;


	while (1)
	{
		if (isatty(0))
			write(1, ">_<: ", 5);

		if (_getline(&line, &buff_size, 0) == -1)
		{
			if (isatty(0))
				printf("\n");
			break;
		}

		sep_cmds = comm_sepa(line);

		while (sep_cmds->cur)
		{
			if (just_spaces(sep_cmds->cur->cmd))
			{
				sep_cmds->cur = sep_cmds->cur->next;
				continue;
			}

			strtrim(sep_cmds->cur->cmd);
			line_number++;
			if (_strncmp(sep_cmds->cur->cmd, "exit", 4) == 0)
				handl_exit(sep_cmds->cur->cmd, line_number, sep_cmds);
			else if (_strncmp(sep_cmds->cur->cmd, "env", 3) == 0)
				handl_env(env);
			else if (_strncmp(sep_cmds->cur->cmd, "cd", 2) == 0)
				handl_chdir(sep_cmds->cur->cmd, line_number, sep_cmds);
			else if (_strncmp(sep_cmds->cur->cmd, "pwd", 3) == 0)
				handl_pwd();
			else
			  exec_program(sep_cmds->cur->cmd, env, line_number);
			sep_cmds->cur = sep_cmds->cur->next;
		}
		free_list(sep_cmds);
		free(line);
	}
}

/**
 * handl_signal - handl ctrl + c
 * @sig: signal to handl
 */
void handl_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n>_<: ");
	fflush(stdout);
}
int just_spaces(char *command)
{
	size_t i;

	for (i = 0; i < strlen(command) - 1; i++)
	{
		if (command[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}

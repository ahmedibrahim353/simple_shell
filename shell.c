#include "main.h"

/**
 * main - shell
 * @argv: 0.24.11
 * @env: Z xcutea
 * Return: Always 0
 */
int main(int _cxt, _dou_p argv, _dou_p env)
{
	size_t buff_size = 0;
	string getline_buff;
	_dou_p local_argv;

	(void)_cxt;
	while (true)
	{
		if (isatty(STDIN_FILENO))
			_print_string("[$] ");
		if ((getline(&getline_buff, &buff_size, stdin)) == EOF)
		{
			_putchar('\n');
			exit(-1);
		}
		if (!(strcmp(getline_buff, "\n")))
			continue;

		local_argv = _tokenization(getline_buff, " \n\t\r");
		if (!(strcmp(local_argv[0], "env")))
		{
			_env();
			continue;
		}
		if (!(strcmp(local_argv[0], "exit")))
		{
			_exit_num(local_argv);
		}

		execmd(local_argv, env, argv);

		free(local_argv);
		if (isatty(STDIN_FILENO) == 0)
			break;
	}
	free(getline_buff);
	return (0);
}

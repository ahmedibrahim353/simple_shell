#include "shell.h"

/**
 * _myexit - function that used to exit
 * @info: Structure  Used to maintain constant function prototype.
 *  Return: exits with exit status
 */

int _myexit(info_t *info)
{
	int ck_exit;

	if (info->argument_list[1])
	{
		ck_exit = _atoierr(info->argument_list[1]);
		if (ck_exit == -1)
		{
			info->return_status = 2;
			print_err(info, "Illegal number: ");
			_eputs(info->argument_list[1]);
			_eputchar('\n');
			return (1);
		}
		info->exit_code = _atoierr(info->argument_list[1]);
		return (-2);
	}
	info->exit_code = -1;
	return (-2);
}

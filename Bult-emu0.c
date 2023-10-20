#include "shell.h"

/**
 * _myexit - exits in shell
 * @info: information
 *  Return: if info.argv[0] != "exit", 0 with given exit status
 */

int _myexit(info_t *info)
{
	int ck;

	if (info->argv[1])
	{
		ck = _erratoi(info->argv[1]);
		if (ck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}

	info->err_num = -1;
	return (-2);
}


/**
 * _mycd - change the process current direct_
 * @info: information
 *  Return: 0
 */

int _mycd(info_t *info)
{
	char *str, *direc, buff[1024];
	int curDirect;

	str = getcwd(buff, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direc = _getenv(info, "HOME=");
		if (!direc)
			curDirect =
				chdir((direc = _getenv(info, "PWD=")) ? direc : "/");
		else
			curDirect = chdir(direc);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		curDirect =
			chdir((direc = _getenv(info, "OLDPWD=")) ? direc : "/");
	}
	else
		curDirect = chdir(info->argv[1]);
	if (curDirect == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}


/**
 * _myhelp - change the process current direc_
 * @info: information
 *  Return: 0
 */

int _myhelp(info_t *info)
{
	char **array;

	array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*array);
	return (0);
}

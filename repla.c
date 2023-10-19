#include "shell.h"


/**
 * rep_vars - replaces vars.
 * @info: struct.
 * Return: 1 or 0.
 */

int rep_vars(info_t *info)
{
	int k = 0;
	list_t *nd;

	for (k = 0; info->argument_list[k]; k++)
	{
		if (info->argument_list[k][0] != '$' || !info->argument_list[k][1])
			continue;

		if (!_strcmp(info->argument_list[k], "$?"))
		{
			rep_str(&(info->argument_list[k]),
					_strdup(conv_num(info->return_status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argument_list[k], "$$"))
		{
			rep_str(&(info->argument_list[k]),
					_strdup(conv_num(getpid(), 10, 0)));
			continue;
		}
		nd = node_starts_with(info->environment, &info->argument_list[k][1], '=');
		if (nd)
		{
			rep_str(&(info->argument_list[k]),
					_strdup(_strchr(nd->str, '=') + 1));
			continue;
		}
		rep_str(&info->argument_list[k], _strdup(""));

	}
	return (0);
}

/**
 * rep_str - replaces a string.
 * @old_string: old.
 * @new_string: new.
 * Return: 1 or 0.
 */

int rep_str(char **old_string, char *new_string)
{
	free(*old_string);
	*old_string = new_string;
	return (1);
}

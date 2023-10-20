#include "shell.h"

/**
 * get_environ - returns the copy array of string
 * @info: info
 * Return: Always (0)
 *
 */


char **get_environ(info_t *info)
{
	if (info->env_changed || !info->environ)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - remove variable of environment
 * @info: info
 *  Return: when delte 1, otherwise 0
 * @var: string
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *str;

	if (!node || !var)
		return (0);

	while (node)
	{
		str = starts_with(node->str, var);

		if (str && *str == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
        
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * _setenv - initialize or modfiy an environment variable
 * @info: info
 * @var: string
 * @value: string
 *  Return: (0)
 *
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *str;

	if (!var || !value)
    {
		return (0);
    }

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
    {
		return (1);
    }
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		str = starts_with(node->str, var);
		if (str && *str == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

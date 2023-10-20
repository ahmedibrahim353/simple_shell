#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command
 * @info: info struct
 * @path: path to file
 * Return: 1 if true, 0 otherwise
 *
*/


int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: PATH string.
 * @start: starting index.
 * @stop: stopping index.
 * Return: pointer to New Buffer
 *
*/


char *dup_chars(char *pathstr, int start, int stop)
{
	int l = 0, i = 0;
	static char buff[1024];

	for (i = 0, l = start; l < stop; l++)
		if (pathstr[l] != ':')
			buff[i++] = pathstr[l];
	buff[j] = 0;

	return (buff);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: info struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 * Return: Full path of cmd if found or null.
 *
*/

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	char *path;
	int l = 0, cr_pos = 0;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[l] || pathstr[l] == ':')
		{
			path = dup_chars(pathstr, cr_pos, l);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[l])
				break;

			cr_pos = l;
		}
		l++;
	}

	return (NULL);
}


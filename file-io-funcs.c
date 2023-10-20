#include "shell.h"

/**
 * get_history_file - history file
 * @info: structure parameter
 *
 * Return: string
 *
 */

char *get_history_file(info_t *info)
{
	char *buff, *direc;

	direc = _getenv(info, "HOME=");

	if (!direc)
    {
		return (NULL);
    }
	buff = malloc(sizeof(char) * (_strlen(direc) + _strlen(HIST_FILE) + 2));
	if (!buff)
    {
		return (NULL);
    }
	buff[0] = 0;
	_strcpy(buff, direc);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - create or append a file
 * @info: structure parameter
 *
 * Return: on success (1), otherwise (-1)
 *
 */
int write_history(info_t *info)
{
	ssize_t fileDirect;
	char *name = get_history_file(info);
	list_t *node = NULL;

	if (!name)
    {
		return (-1);
    }

	fileDirect = open(name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(name);
	if (fileDirect == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fileDirect);
		_putfd('\n', fileDirect);
	}
	_putfd(BUF_FLUSH, fileDirect);
	close(fileDirect);
	return (1);
}

/**
 * read_history - reads history
 * @info: structure parameter
 *
 * Return: on success histcount, otherwise 0
 *
 */

int read_history(info_t *info)
{
	int i, latest = 0, count = 0;
	ssize_t fileDirect, readedLength, fileSize = 0;
	struct stat st;
	char *buffer = NULL, *name = get_history_file(info);

	if (!name)
		return (0);

	fileDirect = open(name, O_RDONLY);
	free(name);
	if (fileDirect == -1)
		return (0);
	if (!fstat(fileDirect, &st))
		fileSize = st.st_size;
	if (fileSize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fileSize + 1));
	if (!buffer)
		return (0);
	readedLength = read(fileDirect, buffer, fileSize);
	buffer[fileSize] = 0;
	if (readedLength <= 0)
		return (free(buffer), 0);
	close(fileDirect);
	for (i = 0; i < fileSize; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			build_history_list(info, buffer + latest, count++);
			latest = i + 1;
		}
	if (latest != i)
		build_history_list(info, buffer + latest, count++);
	free(buffer);
	info->histcount = count;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to list
 * @info: structure parameter
 * @buf: buffer
 * @linecount: linecount history
 *
 * Return: 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
    {
		node = info->history;
    }

	add_node_end(&node, buf, linecount);

	if (!info->history)
    {
		info->history = node;
    }

	return (0);
}

/**
 * renumber_history - renumbers the history
 * @info: structure parameter
 *
 * Return: histcounter
 *
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}

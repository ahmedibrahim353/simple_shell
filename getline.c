#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct.
 * @buf: address of buffer.
 * @len: address of len var.
 * Return: bytes to read
 *
*/

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t t = 0;
	size_t len_b = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		t = getline(buf, &len_b, stdin);
#else
		t = _getline(info, buf, &len_b);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0';
				t--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = t;
				info->cmd_buf = buf;
			}
		}
	}
	return (t);
}

/**
 * get_input - gets a line minus newline
 * @info: parameter struct.
 * Return: bytes to read.
 *
*/

ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t l, G, len;
	ssize_t t = 0;
	char **buf_b = &(info->arg), *a;

	_putchar(BUF_FLUSH);
	t = input_buf(info, &buf, &len);
	if (t == -1)
		return (-1);
	if (len)
	{
		G = l;
		a = buf + l;

		check_chain(info, buf, &G, l, len);
		while (G < len)
		{
			if (is_chain(info, buf, &G))
				break;
			G++;
		}

		l = G + 1;
		if (l >= len)
		{
			l = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_b = a;
		return (_strlen(a));
	}

	*buf_b = buf;

	return (t);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct.
 * @buf: buffer
 * @i: size.
 * Return: t .
 *
*/

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t t = 0;

	if (*i)
		return (0);
	t = read(info->readfd, buf, READ_BUF_SIZE);
	if (t >= 0)
		*i = t;

	return (t);
}

/**
 * _getline - gets next line of input from STDIN
 * @info: parameter struct.
 * @ptr: address pointer to buffer, preallocated or NULL.
 * @length: the size preallocated ptr buffer if not NULL.
 * Return: a
 *
*/

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t l, len;
	size_t j;
	ssize_t t = 0, a = 0;
	char *b = NULL, *new_b = NULL, *x;

	b = *ptr;
	if (b && length)
		a = *length;
	if (l == len)
		l = len = 0;

	t = read_buf(info, buf, &len);
	if (t == -1 || (t == 0 && len == 0))
		return (-1);

	x = _strchr(buf + l, '\n');
	j = x ? 1 + (unsigned int)(x - buf) : len;
	new_b = _realloc(b, a, a ? a + j : j + 1);
	if (!new_b)
		return (b ? free(b), -1 : -1);

	if (a)
		_strncat(new_b, buf + l, j - l);
	else
		_strncpy(new_b, buf + l, j - l + 1);

	a += j - l;
	l = j;
	b = new_b;

	if (length)
		*length = a;
	*ptr = b;
	return (a);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: signal number.
 * Return: void.
 *
*/

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}


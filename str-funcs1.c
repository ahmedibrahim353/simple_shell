#include "shell.h"

/**
 * _strcpy - function copies a string
 * @dest: The destination
 * @src: is the source
 *
 * Return: Destination
 *
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = 0;

	return (dest);
}

/**
 * _strdup - Function duplicates a string
 * @str: a string
 * Return: str
 *
 */


char *_strdup(const char *str)
{
	int length = 0;
	char *ret-Value;

	if (str == NULL)
    {
		return (NULL);
    }
	while (*str++)
		length++;

	ret-Value = malloc(sizeof(char) * (len + 1));

	if (!ret-Value)
    {
		return (NULL);
    }
	for (length++; length--;)
    {
		ret-Value[length] = *--str;
    }
	return (ret-Value);
}

/**
 *_puts - function prints an input string
 *@str: a string
 *
 * Return: Nothing
 *
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		i++;
	}
}

/**
 * _putchar - Function Writes C to stdout
 * @c: a character
 * Return: on success 1, on error -1
 *
 */


int _putchar(char c)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c != BUF_FLUSH)
    {
		buf[y++] = c;
    }
	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}

	return (1);
}

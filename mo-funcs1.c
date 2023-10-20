#include "shell.h"

/**
 * _erratoi - converts from string to an integer
 * @s: string
 * Return: no numbers in string 0, otherwise -1
 *
 */

int _erratoi(char *s)
{
	int x = 0;
	unsigned long int retu-value = 0;

	if (*s == '+')
    {
		s++;
    }
	for (x = 0;  s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			retu-value *= 10;
			retu-value += (s[x] - '0');
			if (retu-value > INT_MAX)
            {
				return (-1);
            }
		}
		else
        {
			return (-1);
        }
	
	}

	return (retu-value);
}

/**
 * print_error - Prints message of error
 * @info: structure parameter
 * @estr: string
 * Return: no numbers in string 0, otherwise -1
 *
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a integer
 * @input: is the input
 * @fd: is the filede scriptor
 *
 * Return: Leng of printed characters
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x, coun = 0;
	unsigned int _abc_, cur;

	if (fd == STDERR_FILENO)
    {
		__putchar = _eputchar;
    }
	if (input < 0)
	{
		_abc_ = -input;
		__putchar('-');
		coun++;
	}
	else
		_abc_ = input;
	cur = _abc_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abc_ / x)
		{
			__putchar('0' + cur / x);
			coun++;
		}
		cur %= x;
	}
	__putchar('0' + cur);
	coun++;

	return (coun);
}

/**
 * convert_number - converter function
 * @num: is a number
 * @base: is a base
 * @flags: is an argument flags
 *
 * Return: String
 *
 */

char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buf[50];
	char mark = 0;
	char *ptrChar;
	unsigned long number = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		number = -num;
		mark = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptrChar = &buf[49];
	*ptrChar = '\0';

	do	{
		*--ptrChar = arr[number % base];
		number /= base;
	} while (number != 0);

	if (mark)
    {
		*--ptrChar = mark;
    }

	return (ptrChar);
}

/**
 * remove_comments - Replaces first # by 0
 * @buf: Address
 *
 * Return: (0);
 *
 */


void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}

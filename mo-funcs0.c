#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 *
*/


int interactive(info_t *info)

{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - checks if character is a delimeter
 * @c: Char to check
 * @delim: Delimeter string
 * Return: 1 if true, 0 if false
 *
*/


int is_delim(char c, char *delim)

{
	while (*delim)

		if (*delim++ == c)

			return (1);
	return (0);
}

/**
 *_isalpha - Checks for alphabetic Character
 *@c: character to input.
 *Return: 1 if c is alphabetic, 0 otherwise
 *
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

		return (1);
	else

		return (0);
}

/**
 *_atoi - Converts a string to an integer
 *@s: string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 *
*/

int _atoi(char *s)

{
	int l, sn = 1, flag = 0, output;
	unsigned int result = 0;

	for (l = 0;  s[l] != '\0' && flag != 2; l++)
	{
		if (s[l] == '-')
			sn *= -1;

		if (s[l] >= '0' && s[l] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[l] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sn == -1)
		output = -result;
	else
		output = result;

	return (output);
}


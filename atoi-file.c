#include "shell.h"

/**
 * _atoi - converts string to integer
 * @str: string
 * Return: 0 or converted number
 */

int _atoi(char *str)
{
	int index, sign = 1, flag = 0, output;
	unsigned int resut = 0;

	for (index = 0; str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] == '-')
			sign *= -1;

		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			resut *= 10;
			resut += (str[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -resut;
	else
		output = resut;

	return (output);
}

/**
 * _atoierr - converts string to int.
 * @st: converted string
 * Return: 0 or -1.
 */

int _atoierr(char *st)
{
	int i = 0;
	unsigned long int res = 0;

	if (*st == '+')
		st++;

	while (st[i] != '\0')
	{
		if (st[i] >= '0' && st[i] <= '9')
		{
			res *= 10;
			res += (st[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return ((int)res);
}

#include "shell.h"

/**
 * bfree - frees all pointer and nulls addresses
 * @ptr: Addresses
 *
 * Return: on freed 1, otherwise 0
 *
 */

int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;

		return (1);
	}

	return (0);
}

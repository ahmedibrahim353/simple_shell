#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: pointer to the memory area
 *@b: byte to fill *s with.
 *@n: amount of bytes to be filled.
 *Return: (s) a pointer to the memory area (s)
 *
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int l;

	for (l = 0; l < n; l++)
		s[l] = b;

	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: String of strings
 *
*/

void ffree(char **pp)
{
	char **z = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(z);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block.
 * @old_size: Byte size of previous block.
 * @new_size: Byte size of new block.
 *
 * Return: Pointer to daol'block nameen
 *
*/


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	char *a;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	a = malloc(new_size);
	if (!a)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		b[old_size] = ((char *)ptr)[old_size];
	free(ptr);

	return (a);
}


#include "main.h"

/**
 *_stringTok - function to execute.
 *@string: string to execute
 *@delim: delimiter
 *Return: 0 on success
 */

char **_stringTok(char *string, char *delim)
{
	char **array_Of_Words = NULL;
	char *token, *temp_ptr = NULL;
	int count;

	temp_ptr = malloc((_strlen(string)) * sizeof(char *));
	if (temp_ptr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(temp_ptr, string);
	count = 0;
	token = strtok(temp_ptr, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(temp_ptr);

	array_Of_Words = malloc((count + 1) * sizeof(char *));
	if (array_Of_Words == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	count = 0;
	token = strtok(string, delim);
	while (token)
	{
		array_Of_Words[count] = token;
		counter++;
		token = strtok(NULL, delim);
	}
	array_Of_Words[count] = NULL;
	return (array_Of_Words);
}

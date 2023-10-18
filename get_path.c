#include "main.h"

char *_get_path(char *command)
{
	char *path = NULL, *path_cp, *path_tok, *file_path;
	int command_length, directory_length;
	struct stat buf;

	path = getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		command_length = _strlen(command);
		path_tok = strtok(path_cp, ":");
		while (path_tok != NULL)
		{
			directory_length = strlen(path_tok);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_tok);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buf) == 0)
			{
				free(path_cp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_cp);
		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}

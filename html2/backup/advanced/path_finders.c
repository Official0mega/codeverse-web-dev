#include "../include/shell.h"

/**
 * path_cmd - Search for the executable command in directories listed in $PATH.
 *
 * @cmd: Parsed input representing the command to search for.
 * Return: 0 on success (command found), 1 on failure (command not found).
 */
int path_cmd(char **cmd)
{
    /*  Variables to store path components and check file status */
	char *path, *value, *cmd_path;
	struct stat buf;

	/*  Retrieve the value of the PATH environment variable */
	path = _getenv("PATH");
	/*  Tokenize the path using ':' as delimiter */
	value = _strtok(path, ":");
	while (value != NULL)
	{
		/*  Build the full path for the command */
		cmd_path = build(*cmd, value);
		/*  Check if the file exists (stat returns 0 on success) */
		if (stat(cmd_path, &buf) == 0)
		{
			/*  Update the command with the full path */
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0); /*  Command found, return success */
		}
		free(cmd_path);
		value = _strtok(NULL, ":"); /*  Move to the next directory in PATH */
	}
	free(path);
	free(value);
	return (1); /*  Command not found, return failure */
}

/**
 * build - Build the full path of the executable command.
 *
 * @token: Executable command.
 * @value: Directory containing the command.
 * Return: Parsed full path of the command or NULL if failed.
 */
char *build(char *token, char *value)
{
	/*  Allocate memory for the full path */
	char *cmd;
	size_t len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL); /*  Memory allocation failure, return NULL */
	}

	memset(cmd, 0, len); /*  Initialize memory to zero */

	/*  Build the full path by concatenating directory, "/", and command */
	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd); /*  Return the full path of the command */
}

/**
 * _getenv - Gets the value of an environment variable by name.
 *
 * @name: Environment variable name.
 * Return: The value of the environment variable or NULL if failed.
 */
char *_getenv(char *name)
{
	/*  Variables to store lengths and the value of the environment variable */
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);

	/*  Iterate through the environment variables */
	for (i = 0 ; environ[i]; i++)
	{
		/*  Check if the current variable matches the specified name */
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			/*  Calculate the length of the value */
			value_len = _strlen(environ[i]) - name_len;
			/*  Allocate memory for the value */
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL); /*  Memory allocation failure, return NULL */
			}

			/*  Copy the value of the environment variable to the allocated memory */
			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value); /*  Return the value of the environment variable */
		}
	}
	return (NULL); /*  Environment variable not found, return NULL */
}

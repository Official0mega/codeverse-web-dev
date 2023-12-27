#include "../include/shell.h"

/**
 * set_environ - Creates an array of Environment Variables.
 * @envi: Array to store Environment Variables.
 */
void set_environ(char **envir)
{
	/*  Declare variable */
	int crt_envr;

	/*  Iterate through the global 'environ' array and copy each environment variable */
	for (crt_envr = 0; environ[crt_envr]; crt_envr++)
		envi[crt_envr] = _strdup(environ[crt_envr]);

	/*  Set the last element of the array to NULL to indicate the end */
	envir[crt_envr] = NULL;
}

/**
 * free_environ - Frees the memory of the created Environment Variables array.
 * @env: Array of Environment variables.
 */
void free_environ(char **env)
{
	/*  Declare variable */
	int crt_envr;

	/*  Iterate through the array of environment variables and free each allocated memory */
	for (crt_envr = 0; env[crt_envr]; crt_envr++)
	{
		free(env[crt_envr]);
	}
}
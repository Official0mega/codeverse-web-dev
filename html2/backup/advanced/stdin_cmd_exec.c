#include "../include/shell.h"

/**
 * check_cmd - Executes commands found in the predefined path.
 *
 * @cmd: Array of parsed command strings.
 * @input: Input received from the user (to be freed).
 * @c: Shell Execution Time Case of Command Not Found.
 * @argv: Arguments before the program starts (argv[0] == Shell Program Name).
 * Return: 1 if command is NULL, -1 if wrong command, 0 if command executed.
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int wstatus;
	pid_t pid;

	/*  Check if command is NULL
 */
	if (*cmd == NULL)
		return (EXIT_FAILURE);

	/*  Create a child process
 */
	pid = fork();

	/*  Check if fork failed
 */
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	/*  Child process
 */
	if (pid == 0)
	{
		/*  If the command is not a relative or absolute path, search in PATH
 */
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);

		/*  Check if the command is executable
 */
		if (access(cmd[0], R_OK) != 0)
		{
			/*  Print error message and exit with status 127
 */
			print_error(cmd[0], c, argv);
			free_all(cmd, input);
			exit(127);
		}

		/*  Execute the command in the child process
 */
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}

	/*  Parent process
 */
	wait(&wstatus);

	/*  Check if the child process exited normally
 */
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}

	/*  Return 127 if child process did not exit normally
 */
	return (127);
}

/**
 * signal_to_handle - Configures ^C not to terminate our shell.
 *
 * @sig: Incoming Signal.
 */
void signal_to_handle(int sig)
{
	/*  Handle SIGINT (Ctrl+C) signal by printing a new prompt
 */
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
